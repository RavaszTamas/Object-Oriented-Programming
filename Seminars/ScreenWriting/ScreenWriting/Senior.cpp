#include "Senior.h"
#include <qstring.h>
#include <string>
#include <qmessagebox.h>
#include "TextEditor.h"
using namespace std;

Senior::Senior(Controller& _controller, IdeasModel* _model,std::string _name, QWidget *parent)
	: QWidget(parent), name{ _name }, model{ _model }, controller{ _controller }
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(name));
	ui.tableView->setModel(model);
	ui.tableView->resizeColumnsToContents();

	ui.tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.developPushButton->setEnabled(false);

	this->checkForDevelop();

	ui.actLineEdit->setValidator(new QRegExpValidator{ QRegExp{ "[1-3]" } });
	ui.descriptionLineEdit->setValidator(new QRegExpValidator{ QRegExp{ "[^\ ]*" } });
	QObject::connect(ui.addPushButton, &QPushButton::clicked, this, &Senior::addNew);
	QObject::connect(ui.acceptPushButton, &QPushButton::clicked, this, &Senior::acceptNewIdea);
	QObject::connect(ui.developPushButton, &QPushButton::clicked, this, &Senior::developAccepted);
	QObject::connect(ui.plotButton, &QPushButton::clicked, this, &Senior::savePlot);
	QObject::connect(model, &IdeasModel::modelReset, this, &Senior::checkForDevelop);
}

Senior::~Senior()
{
}

void Senior::addNew()
{
	string desc = ui.descriptionLineEdit->text().toStdString();
	string act = ui.actLineEdit->text().toStdString();
	if (desc != "" && act != "")
	{
		try {

			this->controller.saveToFile(desc, "proposed", this->name, act);
			this->model->resetModel();
		}
		catch (exception& e)
		{
			QMessageBox::critical(this, "Add error", e.what());
			return;
		}
	}

}

void Senior::developAccepted()
{
	auto elements = this->controller.getAll();
	for (auto it : elements)
	{
		if (it.getCreator() == this->name && it.getStatus() == "accepted")
		{
			TextEditor* newEditor = new TextEditor{ it.getDesc() };
			newEditor->show();
		}
	}

}

void Senior::acceptNewIdea()
{
	QModelIndexList index = ui.tableView->selectionModel()->selectedIndexes();
	if (index.size() == 0)
		return;
	int idx = index.at(0).row();
	if (ui.tableView->model()->index(index.at(0).row(), 1).data().toString() == "proposed")
	{
		if (this->controller.modifyStatus(ui.tableView->model()->index(index.at(0).row(), 0).data().toString().toStdString(), stoi(ui.tableView->model()->index(index.at(0).row(), 3).data().toString().toStdString())) == true)
			this->model->resetModel();
		
	}
}

void Senior::savePlot()
{
	this->controller.savePlot();
}

void Senior::checkForDevelop()
{
	if (ui.developPushButton->isEnabled())
		return;
	auto elements = this->controller.getAll();
	for (auto it : elements)
	{
		if (it.getStatus() == "accepted" && it.getCreator() == this->name)
		{
			ui.developPushButton->setEnabled(true);
			return;
		}
	}
}
