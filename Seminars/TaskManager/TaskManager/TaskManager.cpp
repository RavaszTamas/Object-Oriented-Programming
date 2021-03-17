#include "TaskManager.h"
#include <string>
#include <qmessagebox.h>

using namespace std;

TaskManager::TaskManager(std::string _name,Controller& _controller,QWidget *parent)
	: QMainWindow(parent), controller{ _controller }, name{ _name }
{
	ui.setupUi(this);
	this->controller.registerObserver(this);
	this->setWindowTitle(QString::fromStdString(this->name));
	QObject::connect(ui.addPushButton, &QPushButton::clicked, this, &TaskManager::addTask);
	QObject::connect(ui.removePushButton, &QPushButton::clicked, this, &TaskManager::removeTask);
	QObject::connect(ui.startPushButton, &QPushButton::clicked, this, &TaskManager::startTask);
	QObject::connect(ui.donePushButton, &QPushButton::clicked, this, &TaskManager::finishTask);
	QObject::connect(ui.tableWidget, &QTableWidget::itemSelectionChanged, this, &TaskManager::checkForItemInList);
	ui.donePushButton->setEnabled(false);
	this->update();
}

void TaskManager::update()
{
	ui.tableWidget->clear();
	auto tasks = this->controller.getAllTasks();
	auto programmers = this->controller.getAllProgrammers();
	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->setRowCount(tasks.size());
	ui.tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Description"));
	ui.tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Status"));
	ui.tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Id"));

	for (int i = 0; i < tasks.size(); ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
				if (tasks[i].getStatus() == "in progress")
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString(tasks[i].getDescription() + " (" + this->controller.getNameOfId(tasks[i].getId()) + ")")));
				else
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString(tasks[i].getDescription())));
			else if (j == 1)
				ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString(tasks[i].getStatus())));
			else if (j == 2)
				if(tasks[i].getId() != -1)
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString(to_string(tasks[i].getId()))));
				else
					ui.tableWidget->setItem(i, j, new QTableWidgetItem(""));

		}
	}
	ui.tableWidget->setColumnHidden(2, true);
	ui.tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void TaskManager::addTask()
{
	string description = ui.addLineEdit->text().toStdString();
	if (description == "")
		return;
	this->controller.addTask(description, this->name);
	
}

void TaskManager::removeTask()
{
	QModelIndexList indexes = ui.tableWidget->selectionModel()->selectedIndexes();
	if (indexes.size() == 0)
		return;
	string description = ui.tableWidget->item(indexes.at(0).row(), 0)->text().toStdString();
	string status = ui.tableWidget->item(indexes.at(0).row(), 1)->text().toStdString();
	string sid = ui.tableWidget->item(indexes.at(0).row(), 2)->text().toStdString();
	int id;
	if (sid == "")
		id = -1;
	else
		id = stoi(sid);
	this->controller.removeTask(description, status, id);
}

void TaskManager::startTask()
{
	QModelIndexList index = ui.tableWidget->selectionModel()->selectedIndexes();

	if (index.size() == 0)
		return;
	string description = ui.tableWidget->item(index.at(0).row(), 0)->text().toStdString();
	try {

		this->controller.beginTask(description, this->name);
	}
	catch (RepositoryException& e)
	{
		QMessageBox::critical(this, "Error!", e.what());
	}
}

void TaskManager::finishTask()
{
	QModelIndexList index = ui.tableWidget->selectionModel()->selectedIndexes();

	if (index.size() == 0)
		return;
	string description = ui.tableWidget->item(index.at(0).row(), 0)->text().toStdString();
	int last = description.find_first_of('(');
	description = description.substr(0, last-1);
	this->controller.finishTask(description, this->name);

}

void TaskManager::checkForItemInList()
{
	int myId = this->controller.getIdOfName(this->name);
	QModelIndexList index = ui.tableWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
		return;
	string status = ui.tableWidget->item(index.at(0).row(), 1)->text().toStdString();
	string sid = ui.tableWidget->item(index.at(0).row(), 2)->text().toStdString();
	int id;
	if (sid == "")
		id = -1;
	else
		id = stoi(sid);

	if (status == "in progress" && id == myId)
		ui.donePushButton->setEnabled(true);
	else
		ui.donePushButton->setEnabled(false);
}
