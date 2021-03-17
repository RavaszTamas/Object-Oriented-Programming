#include "Assistant.h"
#include <string>
#include <QRegExpValidator>
#include <qmessagebox.h>
#include "IdeasModel.h"
#include "TextEditor.h"

using namespace std;

Assistant::Assistant(Controller& _controller, IdeasModel* _model, std::string _name, QWidget *parent)
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
	ui.lineEditDescription->setValidator(new QRegExpValidator{ QRegExp{ "[^\ ]*" } });
	ui.lineEditAct->setValidator(new QRegExpValidator{ QRegExp{"[1-3]"} });
	QObject::connect(ui.addPushButton, &QPushButton::clicked, this, &Assistant::addNew);
	QObject::connect(ui.developPushButton, &QPushButton::clicked, this, &Assistant::developAccepted);
	QObject::connect(ui.plotButton, &QPushButton::clicked, this, &Assistant::savePlot);
	QObject::connect(model, &IdeasModel::modelReset, this, &Assistant::checkForDevelop);
}
Assistant::~Assistant()
{
}

void Assistant::developAccepted()
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

void Assistant::addNew()
{
	string desc = ui.lineEditDescription->text().toStdString();
	string act = ui.lineEditAct->text().toStdString();
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

void Assistant::savePlot()
{
	this->controller.savePlot();
}

void Assistant::checkForDevelop()
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
