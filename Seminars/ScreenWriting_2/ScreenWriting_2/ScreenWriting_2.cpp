#include "ScreenWriting_2.h"
#include <exception>
#include <qdebug.h>

using namespace std;


ScreenWriting_2::ScreenWriting_2(Controller& _controller,IdeaModel* _model,std::string _name, std::string _rank,QWidget *parent)
	: QMainWindow(parent), model{ _model }, controller{ _controller }, rank{ _rank }, name{ _name }
{
	ui.setupUi(this);
	ui.developPushButton->setEnabled(false);
	ui.tableView->setModel(model);
	ui.tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->setWindowTitle(QString::fromStdString(this->name));
	if (rank != "Senior")
		ui.acceptPushButton->setHidden(true);
	ui.actLineEdit->setValidator(new QRegExpValidator{ QRegExp{"[1-3]"} });
	QObject::connect(ui.addPushButton, &QPushButton::clicked, this, &ScreenWriting_2::uiAddNew);
	QObject::connect(ui.acceptPushButton, &QPushButton::clicked, this, &ScreenWriting_2::acceptIdea);
	QObject::connect(ui.tableView->model(), &IdeaModel::modelReset, this, &ScreenWriting_2::checkForDevelop);
	QObject::connect(ui.developPushButton, &QPushButton::clicked, this, &ScreenWriting_2::openDevelopment);
	QObject::connect(ui.tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &ScreenWriting_2::doStuff);
	this->checkForDevelop();
}

void ScreenWriting_2::uiAddNew()
{
	auto desc = ui.descLineEdit->text().toStdString();
	auto act = ui.actLineEdit->text().toStdString();
	if (desc == "" || act == "")
		return;
	try {

		this->controller.addElement(desc, std::string("proposed"), this->name, act);
		this->model->reset();
	}
	catch(std::exception& e){}

}

void ScreenWriting_2::acceptIdea()
{
	auto index = ui.tableView->selectionModel()->selectedIndexes();
	int row = index.at(0).row();
	if (ui.tableView->model()->index(row, 1).data().toString().toStdString() == "accepted")
		return;

	this->controller.acceptIdea(ui.tableView->model()->index(row, 0).data().toString().toStdString(), ui.tableView->model()->index(row,1).data().toString().toStdString(), ui.tableView->model()->index(row, 2).data().toString().toStdString(), ui.tableView->model()->index(row, 3).data().toString().toStdString());
	this->model->reset();

}

void ScreenWriting_2::checkForDevelop()
{
	if (this->controller.checkForDevelopment(this->name))
		ui.developPushButton->setEnabled(true);
}

void ScreenWriting_2::openDevelopment()
{
	auto elements = this->controller.getAll();

	for (auto it : elements)
	{
		if (it.getCreator() == this->name && it.getStatus() == "accepted")
		{
			TextEditor* newEditor = new TextEditor{ it.getDescription() };
			newEditor->show();
		}
	}

}

void ScreenWriting_2::doStuff()
{
	qDebug() << "A";
}
