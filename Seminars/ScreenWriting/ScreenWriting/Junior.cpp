#include "Junior.h"
#include <string>
#include <qmessagebox.h>
#include "TextEditor.h"

using namespace std;

Junior::Junior(Controller& _controller, IdeasModel* _model,std::string _name, QWidget *parent)
	: QWidget(parent), name{ _name }, model{ _model }, controller{ _controller }
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(name));
	ui.developPushButton->setEnabled(false);
	this->checkForDevelop();
	ui.tableView->setModel(model);
	ui.tableView->resizeColumnsToContents();
	ui.tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.actLineEdit->setValidator(new QRegExpValidator{ QRegExp{ "[1-3]" } });
	ui.descriptionLineEdit->setValidator(new QRegExpValidator{ QRegExp{ "[^\ ]*" } });
	QObject::connect(ui.addPushButton, &QPushButton::clicked, this, &Junior::addNew);
	QObject::connect(ui.developPushButton, &QPushButton::clicked, this, &Junior::developAccepted);
	QObject::connect(ui.plotButton, &QPushButton::clicked, this, &Junior::savePlot);
	QObject::connect(model, &IdeasModel::modelReset, this, &Junior::checkForDevelop);
}

Junior::~Junior()
{
}

void Junior::developAccepted()
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

void Junior::addNew()
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

void Junior::savePlot()
{
	this->controller.savePlot();
}
void Junior::checkForDevelop()
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
