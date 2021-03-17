#include "MyListView.h"
#include "myexceptions.h"
#include <qmessagebox.h>
#include <string>
#include <iostream>

MyListViewModel::MyListViewModel(AppController& _controller, QObject * parent): QAbstractTableModel { parent }, controller{ _controller }
{
}

MyListViewModel::~MyListViewModel()
{

}

int MyListViewModel::columnCount(const QModelIndex & parent) const
{
	return 5;
}


int MyListViewModel::rowCount(const QModelIndex & parent) const
{
	return this->controller.fileMyListManager->readFile().size();

}

void MyListViewModel::resetModel()
{
	this->beginResetModel();
	this->endResetModel();
}

QVariant MyListViewModel::data(const QModelIndex & index, int role) const
{
	/*
	std::vector<Plant> plants = this->controller.fileMyListManager->readFile();
	int row = index.row();
	Plant plant = plants[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		return QString::fromStdString(plant.toString());
	}
	return QVariant{};
	*/
	int row = index.row();
	int column = index.column();

	// get the genes
	std::vector<Plant> plants = this->controller.fileMyListManager->readFile();

	// Allow adding in the table
	// this is to show an empty row at the end of the table - to allow adding new genes
	if (row == plants.size())
	{
		return QVariant();
	}

	// get the gene from the current row
	Plant plant= plants[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(plant.getCodeName());
		case 1:
			return QString::fromStdString(plant.getSpecies());
		case 2:
			return QString::fromStdString(to_string(plant.getAgeInMonths()));
		case 3:
			return QString::fromStdString(plant.getDigitizedScan());
		default:
			break;
		}
	}
	return QVariant();

}

QVariant MyListViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Code name" };
			case 1:
				return QString{ "Species" };
			case 2:
				return QString{ "Age in months" };
			case 3:
				return QString{ "Digitized scan" };
			case 4:
				return QString{ "Illustration" };
			default:
				break;
			}
		}
	}
	/*
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}
	*/

	return QVariant();
}

void MyListWindow::filterPlantsButtonHandler()
{
	if (!this->verifyNoSpaces())
		return;

	QString species = this->speciesEdit->text();
	QString ageInMonths = this->ageInMonthEdit->text();

	if (ageInMonths.size() == 0)
		return;

	try
	{
		stoi(ageInMonths.toStdString());
	}
	catch (invalid_argument)
	{
		return;
	}
	catch (out_of_range)
	{
		return;
	}


	if (species.size() == 0)
	{
		string emptystring = "";
		emit FilterPlantsSignal(emptystring, stoi(ageInMonths.toStdString()));
	}
	else
	{
		emit FilterPlantsSignal(species.toStdString(), stoi(ageInMonths.toStdString()));
	}


}

void MyListWindow::saveToUprootListButtonHandler()
{
	if (!this->verifyNoSpaces())
		return;

	QString codeNameParameter = this->codeNameEdit->text();
	if (codeNameParameter.size() == 0)
		return;

	emit SaveToUprootListSignal(codeNameParameter.toStdString());

}

void MyListWindow::openUprootListHandler()
{
	emit OpenUprootListSignal();
}

void MyListWindow::nextItem()
{
	Plant nextPlant = this->controller.getCurrentPlantByNext();
	string codeName = nextPlant.getCodeName();
	string species = nextPlant.getSpecies();
	string ageInMonths;
	if (codeName == "")
		ageInMonths = "";
	else
		ageInMonths = to_string(nextPlant.getAgeInMonths());

	string digigitzedScan = nextPlant.getDigitizedScan();

	this->codeNameEdit->setText(QString::fromStdString(codeName));
	this->speciesEdit->setText(QString::fromStdString(species));
	this->ageInMonthEdit->setText(QString::fromStdString(ageInMonths));
	this->digitizedScanEdit->setText(QString::fromStdString(digigitzedScan));

}

void MyListWindow::executeUndo()
{
	try {
		this->controller.undoActionUprootList();
	}
	catch (ServiceException& excep)
	{
		QMessageBox::critical(this, "My application", excep.what());
		return;
	}
	this->model->resetModel();

}

void MyListWindow::executeRedo()
{
	try {
		this->controller.redoActionUprootList();
	}
	catch (ServiceException& excep)
	{
		QMessageBox::critical(this, "My application", excep.what());
		return;
	}
	this->model->resetModel();

}
bool MyListWindow::verifyNoSpaces()
{
	string codeName = this->codeNameEdit->text().toStdString();
	string species = this->speciesEdit->text().toStdString();
	string ageInMonths = this->ageInMonthEdit->text().toStdString();
	string digitizedScan = this->digitizedScanEdit->text().toStdString();
	if (std::find_if(codeName.begin(), codeName.end(), [](char x) {return x == ' '; }) != codeName.end())
	{
		QMessageBox::critical(this, "My application", "Invalid input! No spaces in the input!");
		return false;
	}
	if (std::find_if(codeName.begin(), codeName.end(), [](char x) {return x == ' '; }) != codeName.end())
	{
		QMessageBox::critical(this, "My application", "Invalid input! No spaces in the input!");
		return false;
	}
	if (std::find_if(codeName.begin(), codeName.end(), [](char x) {return x == ' '; }) != codeName.end())
	{
		QMessageBox::critical(this, "My application", "Invalid input! No spaces in the input!");
		return false;
	}
	if (std::find_if(codeName.begin(), codeName.end(), [](char x) {return x == ' '; }) != codeName.end())
	{
		QMessageBox::critical(this, "My application", "Invalid input! No spaces in the input!");
		return false;
	}
	return true;
}

void MyListWindow::populateFilterList(std::vector<Plant> plants)
{
	if (this->listViewWidget->count() > 0)
		this->listViewWidget->clear();

	for (auto plant : plants)
	{
		QString itemInList = QString::fromStdString(plant.getCodeName() + "  " + plant.getSpecies() + "  " + std::to_string(plant.getAgeInMonths()) + "  " + plant.getDigitizedScan());
		QFont f{ "Verdana", 10 };
		QListWidgetItem* itemPlant = new QListWidgetItem{ itemInList };
		itemPlant->setFont(f);
		this->listViewWidget->addItem(itemPlant);
	}

	if (plants.size() > 0)
		this->listViewWidget->setCurrentRow(0);
}

void MyListWindow::closeEvent(QCloseEvent * event)
{
	this->originalGUI->switchModeAction();
	this->originalGUI->setEnabled(true);
}

void MyListWindow::connectSlots()
{

	this->CTRLZ = new QShortcut(this);
	CTRLZ->setKey(Qt::CTRL + Qt::Key_Z); // Set the key code
	QObject::connect(this->CTRLZ, SIGNAL(activated()), this, SLOT(executeUndoSlot()));
	this->CTRLY = new QShortcut(this);
	CTRLY->setKey(Qt::CTRL + Qt::Key_Y); // Set the key code
	QObject::connect(this->CTRLY, SIGNAL(activated()), this, SLOT(executeRedoSlot()));

	//QObject::connect(this, &MyListWindow::uprootUpdateSignal, this, &MyListWindow::populateUprootList);

	QObject::connect(this->filterPlantsButton, &QPushButton::clicked, this, &MyListWindow::filterPlantsButtonHandler);

	QObject::connect(this->saveToUprootListButton, &QPushButton::clicked, this, &MyListWindow::saveToUprootListButtonHandler);

	QObject::connect(this->openUprootListButton, &QPushButton::clicked, this, &MyListWindow::openUprootListHandler);

	QObject::connect(this->nextButton, &QPushButton::clicked, this, &MyListWindow::nextItem);

	QObject::connect(this->undoButton, &QPushButton::clicked, this, &MyListWindow::executeUndo);

	QObject::connect(this->redoButton, &QPushButton::clicked, this, &MyListWindow::executeRedo);

	QObject::connect(this, SIGNAL(SaveToUprootListSignal(const std::string&)), this, SLOT(SaveToUprootList(const std::string&)));

	QObject::connect(this, SIGNAL(FilterPlantsSignal(const std::string&, const int)), this, SLOT(FilterPlants(const std::string&, const int)));

	QObject::connect(this, SIGNAL(OpenUprootListSignal()), this, SLOT(OpenUprootList()));

}

MyListWindow::MyListWindow(MyListViewModel * m, AppController& _paramController, PlantsGUI* _originalGUI, QWidget * parent) : QWidget(parent), model{ m }, originalGUI{ _originalGUI }, controller{ _paramController }
{
	this->setupUi(this);
	this->originalGUI->setEnabled(false);
	this->tableView->setModel(this->model);
	this->tableView->setItemDelegate(new PictureDelegate{});
	this->connectSlots();
//	this->tableView->resizeColumnsToContents();
}

MyListWindow::~MyListWindow()
{
}


void MyListWindow::SaveToUprootList(const std::string & codeName)
{
	try {

		this->controller.saveToUprootList(codeName);
	}
	catch (ServiceException& servexcep)
	{
		QMessageBox::critical(this, "My application", servexcep.what());
	}
	catch (RepositoryException& repoexcep)
	{
		QMessageBox::critical(this, "My application", repoexcep.what());
	}
	this->model->resetModel();
}


void MyListWindow::FilterPlants(const std::string & species, const int ageInMonths)
{
	vector<Plant> filteredPlants = this->controller.displayPlantClutersByAgeAndSpecies(species, ageInMonths);
	this->populateFilterList(filteredPlants);
}

void MyListWindow::OpenUprootList()
{
	this->controller.displayChosenPlantClusters();
}

void MyListWindow::executeRedoSlot()
{
	this->executeRedo();
}

void MyListWindow::executeUndoSlot()
{
	this->executeUndo();
}
