#include "gui.h"
#include <algorithm>
#include "myexceptions.h"
#include <qmessagebox.h>
#include <sstream>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <map>
#include <QDebug>
#include "MyListView.h"

using namespace std;


PlantsGUI::PlantsGUI(string mylistType,AppController& _paramController, QWidget *parent) : QMainWindow(parent), controller{ _paramController }
{
	this->mode = "A";
	this->controller.SetMode(string("A"));
	this->mylistype = mylistType;
	ui.setupUi(this);

	this->CTRLZ = new QShortcut(this);
	CTRLZ->setKey(Qt::CTRL + Qt::Key_Z); // Set the key code
	QObject::connect(this->CTRLZ, SIGNAL(activated()), this, SLOT(executeUndoSlot()));
	this->CTRLY = new QShortcut(this);
	CTRLY->setKey(Qt::CTRL + Qt::Key_Y); // Set the key code
	QObject::connect(this->CTRLY, SIGNAL(activated()), this, SLOT(executeRedoSlot()));

	this->buildWindow();
	this->connectSignalsAndSlots();
	this->controller.SetMode(string("A"));
	this->controller.ApplyFileLocation(string("lab11gui.txt"));
	if(mylistType == "csv")
		this->controller.ApplyMyListLocation(string("C:\\Users\\tamas\\Documents\\UBB\\OOP\\Lab11\\Lab11\\lab11guimylist.csv"));
	else if(mylistType == "html")
		this->controller.ApplyMyListLocation(string("C:\\Users\\tamas\\Documents\\UBB\\OOP\\Lab11\\Lab11\\lab11guimylist.html"));
	else
		this->controller.ApplyMyListLocation(string(""));

	this->populatePlantsList();
	this->populateUprootList();
}

PlantsGUI::~PlantsGUI()
{
}

void PlantsGUI::buildWindow()
{
	//General layout of the window


	QWidget* centralWidget = new QWidget{};



	QVBoxLayout* mainLayout = new QVBoxLayout{ centralWidget };


	this->tabWidget = new QTabWidget{ centralWidget };

	this->tabOne = new QWidget{};

	QHBoxLayout* layoutTabOne = new QHBoxLayout{ tabOne };



	QWidget* leftSide = new QWidget{};

	QVBoxLayout* leftPlantsManagerLayout = new QVBoxLayout{ leftSide };
	//name of the list
	QLabel* PlantListLabel = new QLabel{ "All plants" };

	// left side - just the list
	this->plantList = new QListWidget{};
	// set the selection model
	this->plantList->setSelectionMode(QAbstractItemView::SingleSelection);
	//layout->addWidget(this->plantList);

	leftPlantsManagerLayout->addWidget(PlantListLabel);
	leftPlantsManagerLayout->addWidget(this->plantList);



	// right side - gene information + buttons

	// plant information
	QWidget* plantDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ plantDataWidget };
	this->codeNameEdit = new QLineEdit{};
	this->speciesEdit = new QLineEdit{};
	this->ageInMonthEdit = new QLineEdit{};
	this->digitizedScanEdit = new QLineEdit{};

	QFont font{ "Verdana", 10 };
	QLabel* codeNameLabel = new QLabel{ "&Plant code name:" };
	codeNameLabel->setBuddy(this->codeNameEdit);

	QLabel* speciesLabel = new QLabel{ "&Species : " };
	speciesLabel->setBuddy(this->speciesEdit);

	QLabel* ageInMonthsLabel = new QLabel{ "&Age in months:" };
	ageInMonthsLabel->setBuddy(this->ageInMonthEdit);

	QLabel* digitizedScanLabel = new QLabel{ "&Digitized scan:" };
	digitizedScanLabel->setBuddy(this->digitizedScanEdit);


	codeNameLabel->setFont(font);
	speciesLabel->setFont(font);
	ageInMonthsLabel->setFont(font);
	digitizedScanLabel->setFont(font);

	this->codeNameEdit->setFont(font);
	this->speciesEdit->setFont(font);
	this->ageInMonthEdit->setFont(font);
	this->digitizedScanEdit->setFont(font);

	formLayout->addRow(codeNameLabel, this->codeNameEdit);
	formLayout->addRow(speciesLabel, this->speciesEdit);
	formLayout->addRow(ageInMonthsLabel, this->ageInMonthEdit);
	formLayout->addRow(digitizedScanLabel, this->digitizedScanEdit);

	leftPlantsManagerLayout->addWidget(plantDataWidget);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* hLayout = new QGridLayout{ buttonsWidget };

	this->addPlantButton = new QPushButton("Add Plant");
	this->addPlantButton->setFont(font);

	this->removePlantButton = new QPushButton("Remove Plant");
	this->removePlantButton->setFont(font);

	this->updatePlantButton = new QPushButton{ "Update Plant" };
	this->updatePlantButton->setFont(font);

	this->filterPlantsButton = new QPushButton{ "Filter Plants" };
	this->filterPlantsButton->setFont(font);
	this->filterPlantsButton->setEnabled(false);

	this->undoButton = new QPushButton{ "Undo" };
	this->undoButton->setFont(font);
	this->undoButton->setEnabled(true);

	this->redoButton = new QPushButton{ "Redo" };
	this->redoButton->setFont(font);
	this->redoButton->setEnabled(true);


	this->switchMode = new QPushButton{ "Switch mode" };
	this->switchMode->setFont(font);

	this->nextButton = new QPushButton{ "Next" };
	this->nextButton->setFont(font);
	this->nextButton->setEnabled(false);

	this->resetView = new QPushButton{ "Reset view" };
	this->resetView->setFont(font);


	hLayout->addWidget(this->addPlantButton, 0, 0);
	hLayout->addWidget(this->removePlantButton, 0, 1);
	hLayout->addWidget(this->updatePlantButton, 0, 2);
	//hLayout->addWidget(this->filterPlantsButton, 1, 1);
	hLayout->addWidget(this->resetView, 2, 2);
	hLayout->addWidget(this->undoButton, 2, 0);
	hLayout->addWidget(this->redoButton, 2, 1);
	hLayout->addWidget(this->switchMode, 1, 1);

	leftPlantsManagerLayout->addWidget(buttonsWidget);

	QWidget* rightSide = new QWidget{};
	QVBoxLayout* rightMyListLayout = new QVBoxLayout{ rightSide };

	QLabel* mylistLabel = new QLabel{ "Uproot list" };

	this->uprootPlantList = new QListWidget{};

	this->uprootPlantList->setSelectionMode(QAbstractItemView::SingleSelection);


	rightMyListLayout->addWidget(mylistLabel);
	rightMyListLayout->addWidget(this->uprootPlantList);

	QWidget* myListButtons = new QWidget{};
	QVBoxLayout* myListButtonsLayout = new QVBoxLayout{ myListButtons };

	this->openUprootListButton = new QPushButton{ "Open uproot list" };
	this->openUprootListButton->setFont(font);
	this->openUprootListButton->setEnabled(false);

	rightMyListLayout->addWidget(this->openUprootListButton);
	rightMyListLayout->addWidget(this->nextButton);
	// add everything to the big layout
	layoutTabOne->addWidget(leftSide);

	this->saveToUprootListButton = new QPushButton{ ">" };
	this->saveToUprootListButton->setFont(font);

	//layoutTabOne->addWidget(this->saveToUprootListButton);
	//layoutTabOne->addWidget(this->switchMode);
	//layoutTabOne->addWidget(rightSide);



	this->tabWidget->addTab(this->tabOne, QString("Main interface"));

	this->tabTwo = new QWidget();


	QHBoxLayout* layoutTabTwo = new QHBoxLayout{ tabTwo };


	//tabTwo->setObjectName(QString::fromUtf8("tab_2"));



	/*Test bar chart*/

	this->setOfValues = new QBarSet("");
	//QBarSet* set1 = new QBarSet("");
	/*QBarSet* set2 = new QBarSet("dued");
	QBarSet* set3 = new QBarSet("peter");
	QBarSet* set4 = new QBarSet("jeff");
	*/
	//*set0 << 12 << 11;
	*this->setOfValues << 12 << 13;
	//*set1 << 15 << 11;
	/**set2 << 17 << 11;
	*set3 << 30 << 24;
	*set4 << 12 << 11;
	*/
	this->seriesOfValues = new QBarSeries();
	this->seriesOfValues->append(this->setOfValues);
	//series->append(set0);
	//seriesOfValues->append(set1);
	/*series->append(set2);
	series->append(set3);
	series->append(set4);
	*/
	this->chartOfPlants = new QChart{};

	this->chartOfPlants->addSeries(seriesOfValues);
	this->chartOfPlants->setTitle("Plant species statistic");

	this->chartOfPlants->setAnimationOptions(QChart::AllAnimations);


	//categories << "2013" << "2014";
	//this->speciesNames  << "dude" << "peter";
	this->axis = new QBarCategoryAxis{};

	this->axis->append(this->speciesNames);

	this->chartOfPlants->createDefaultAxes();
	this->chartOfPlants->setAxisX(this->axis, this->seriesOfValues);
	this->chartOfPlants->legend()->setVisible(true);
	this->chartOfPlants->legend()->setAlignment(Qt::AlignBottom);

	this->chartView = new QChartView{ this->chartOfPlants };

	this->chartView->setRenderHint(QPainter::Antialiasing);
	QPalette palette = qApp->palette();
	palette.setColor(QPalette::Window, QRgb(0xffffff));
	palette.setColor(QPalette::WindowText, QRgb(0x404040));


	/*end test bar chart*/

	layoutTabTwo->addWidget(this->chartView);





	tabWidget->addTab(tabTwo, QString("Bar chart"));

	mainLayout->addWidget(tabWidget);

	this->setCentralWidget(centralWidget);

}

void PlantsGUI::connectSignalsAndSlots()
{
	//When the list is updated repopulate the list
	QObject::connect(this, &PlantsGUI::plantsUpdateSignal, this, &PlantsGUI::populatePlantsList);
	
	QObject::connect(this, &PlantsGUI::uprootUpdateSignal, this, &PlantsGUI::populateUprootList);

	//Switch targeted elemenent when selected
	QObject::connect(this->plantList,&QListWidget::itemSelectionChanged ,this, [this]() {this->listItemChanged(); });

	QObject::connect(this->addPlantButton, &QPushButton::clicked, this, &PlantsGUI::addPlantButtonHandler);

	QObject::connect(this->removePlantButton, &QPushButton::clicked, this, &PlantsGUI::removePlantButonHandler);

	QObject::connect(this->updatePlantButton, &QPushButton::clicked, this, &PlantsGUI::updatePlantButtonHandler);

	QObject::connect(this->filterPlantsButton, &QPushButton::clicked, this, &PlantsGUI::filterPlantsButtonHandler);

	QObject::connect(this->saveToUprootListButton, &QPushButton::clicked, this, &PlantsGUI::saveToUprootListButtonHandler);

	QObject::connect(this->openUprootListButton, &QPushButton::clicked, this, &PlantsGUI::openUprootListHandler);

	QObject::connect(this->resetView, &QPushButton::clicked, this, &PlantsGUI::populatePlantsList);

	QObject::connect(this->switchMode, &QPushButton::clicked, this, &PlantsGUI::switchModeAction);

	QObject::connect(this->nextButton, &QPushButton::clicked, this, &PlantsGUI::nextItem);

	QObject::connect(this->undoButton, &QPushButton::clicked, this, &PlantsGUI::executeUndo);

	QObject::connect(this->redoButton, &QPushButton::clicked, this, &PlantsGUI::executeRedo);


	QObject::connect(this, SIGNAL(AddPlantSignal(const std::string&, const std::string&, const int, const std::string&)),this,SLOT(AddPlant(const std::string&, const std::string&, const int, const std::string&)));

	QObject::connect(this, SIGNAL(RemovePlantSignal(const std::string&)), this, SLOT(RemovePlant(const std::string&)));

	QObject::connect(this, SIGNAL(UpdatePlantSignal(const std::string&, const std::string&, const int, const std::string&)), this, SLOT(UpdatePlant(const std::string&, const std::string&, const int, const std::string&)));

	QObject::connect(this, SIGNAL(SaveToUprootListSignal(const std::string&)), this, SLOT(SaveToUprootList(const std::string&)));

	QObject::connect(this, SIGNAL(FilterPlantsSignal(const std::string&, const int)), this, SLOT(FilterPlants(const std::string&, const int)));

	QObject::connect(this, SIGNAL(OpenUprootListSignal()), this, SLOT(OpenUprootList()));


}

void PlantsGUI::populatePlantsList()
{
	QBarSet* newset = new QBarSet{ "" };

	if (this->plantList->count() > 0)
		this->plantList->clear();

	if (this->mode == "B")
		return;

	vector<Plant> allPlants= this->controller.listAll();

	map<string, int> dataOfChart;

	for (auto plant : allPlants)
	{
		map<string, int>::iterator iteratormap = dataOfChart.find(plant.getSpecies());
		if (iteratormap == dataOfChart.end()) {
			dataOfChart[plant.getSpecies()] = 1;
		}
		else
		{
			dataOfChart[plant.getSpecies()]++;
		}

		QString itemInList = QString::fromStdString(plant.getCodeName() + "  " + plant.getSpecies() + "  " + std::to_string(plant.getAgeInMonths()) + "  " + plant.getDigitizedScan());
		QFont f{ "Verdana", 10 };
		QListWidgetItem* itemPlant = new QListWidgetItem{ itemInList };
		itemPlant->setFont(f);
		this->plantList->addItem(itemPlant);
	}

	for (auto chartItem : dataOfChart)
	{
		this->speciesNames << chartItem.first.c_str();
		*newset << chartItem.second;
	}
	this->seriesOfValues->clear();

	this->seriesOfValues->append(newset);

	this->axis->clear();
	this->axis->append(this->speciesNames);

	if (allPlants.size() > 0)
		this->plantList->setCurrentRow(0);


}

void PlantsGUI::populateUprootList()
{
	if (this->uprootPlantList->count() > 0)
		this->uprootPlantList->clear();

	vector<Plant> allUprootPlants = this->controller.listAllUprootPlants();


	for (auto plant : allUprootPlants)
	{
		QString itemInList = QString::fromStdString(plant.getCodeName() + "  " + plant.getSpecies() + "  " + std::to_string(plant.getAgeInMonths()) + "  " + plant.getDigitizedScan());
		QFont f{ "Verdana", 10 };
		QListWidgetItem* itemPlant = new QListWidgetItem{ itemInList };
		itemPlant->setFont(f);
		this->uprootPlantList->addItem(itemPlant);
	}

	if (allUprootPlants.size() > 0)
		this->uprootPlantList->setCurrentRow(0);




}

void PlantsGUI::populatePlantsListWithVector(std::vector<Plant> plants)
{
	if (this->plantList->count() > 0)
		this->plantList->clear();

	for (auto plant : plants)
	{
		QString itemInList = QString::fromStdString(plant.getCodeName() + "  " + plant.getSpecies() + "  " + std::to_string(plant.getAgeInMonths()) + "  " + plant.getDigitizedScan());
		QFont f{ "Verdana", 10 };
		QListWidgetItem* itemPlant = new QListWidgetItem{ itemInList };
		itemPlant->setFont(f);
		this->plantList->addItem(itemPlant);
	}

	if (plants.size() > 0)
		this->plantList->setCurrentRow(0);

}

void PlantsGUI::nextItem()
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

void PlantsGUI::reset()
{
}

void PlantsGUI::executeUndo()
{
	try {
		this->controller.undoAction();
	}
	catch (ServiceException& excep)
	{
		QMessageBox::critical(this, "My application", excep.what());
		return;
	}
	emit plantsUpdateSignal();

}

void PlantsGUI::executeRedo()
{
	try {
		this->controller.redoAction();
	}
	catch (ServiceException& excep)
	{
		QMessageBox::critical(this, "My application", excep.what());
		return;
	}
	emit plantsUpdateSignal();

}

void PlantsGUI::listItemChanged()
{
	int index = this->getSelectedIndex();
	if (index == -1)
		return;

	// get the song at the selected index
	// here plant should be called from repo
	vector<Plant> allPlants = this->controller.listAll();

	if (index >= allPlants.size())
		return;

	stringstream auxilliaryss;
	QString item = this->plantList->item(index)->text();
	auxilliaryss << item.toStdString();
	string codeName;
	string species;
	string ageInMonths;
	string digigitzedScan;
	auxilliaryss >> codeName >> species >> ageInMonths >> digigitzedScan;

	this->codeNameEdit->setText(QString::fromStdString(codeName));
	this->speciesEdit->setText(QString::fromStdString(species));
	this->ageInMonthEdit->setText(QString::fromStdString(ageInMonths));
	this->digitizedScanEdit->setText(QString::fromStdString(digigitzedScan));


}

int PlantsGUI::getSelectedIndex()
{
	if (this->plantList->count() == 0)
		return -1;
	QModelIndexList index = this->plantList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->codeNameEdit->clear();
		this->speciesEdit->clear();
		this->ageInMonthEdit->clear();
		this->digitizedScanEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;


}

void PlantsGUI::addPlantButtonHandler()
{
	if (!this->verifyNoSpaces())
		return;
	QString codeName = this->codeNameEdit->text();
	if (codeName.size() == 0)
		return;
	QString species = this->speciesEdit->text();
	if (species.size() == 0)
		return;
	QString ageInMonths = this->ageInMonthEdit->text();
	if (ageInMonths.size() == 0)
		return;
	else
	{
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

	}
	QString digitizedScan = this->digitizedScanEdit->text();
	if (digitizedScan.size() == 0)
		return;
	emit AddPlantSignal(codeName.toStdString(),species.toStdString(),std::stoi(ageInMonths.toStdString()),digitizedScan.toStdString());
}

void PlantsGUI::removePlantButonHandler()
{
	if (!this->verifyNoSpaces())
		return;

	QString codeName = this->codeNameEdit->text();
	if (codeName.size() == 0)
		return;
	emit RemovePlantSignal(codeName.toStdString());
}

void PlantsGUI::updatePlantButtonHandler()
{
	if (!this->verifyNoSpaces())
		return;

	QString codeName = this->codeNameEdit->text();
	if (codeName.size() == 0)
		return;
	QString species = this->speciesEdit->text();
	if (species.size() == 0)
		return;
	QString ageInMonths = this->ageInMonthEdit->text();
	if (ageInMonths.size() == 0)
		return;
	else
	{
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

	}
	QString digitizedScan = this->digitizedScanEdit->text();
	if (digitizedScan.size() == 0)
		return;
	emit UpdatePlantSignal(codeName.toStdString(),species.toStdString(),std::stoi(ageInMonths.toStdString()),digitizedScan.toStdString());
}

void PlantsGUI::filterPlantsButtonHandler()
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

void PlantsGUI::saveToUprootListButtonHandler()
{
	if (!this->verifyNoSpaces())
		return;

	QString codeNameParameter = this->codeNameEdit->text();
	if (codeNameParameter.size() == 0)
		return;

	emit SaveToUprootListSignal(codeNameParameter.toStdString());
}

void PlantsGUI::openUprootListHandler()
{
	emit OpenUprootListSignal();
}

bool PlantsGUI::verifyNoSpaces()
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

void PlantsGUI::switchModeAction()
{
	if (this->mode == "A")
	{
		this->mode = "B";
		this->addPlantButton->setEnabled(false);
		this->removePlantButton->setEnabled(false);
		this->updatePlantButton->setEnabled(false);
		this->undoButton->setEnabled(false);
		this->redoButton->setEnabled(false);
		this->resetView->setEnabled(false);
		this->switchMode->setEnabled(false);
		/*this->nextButton->setEnabled(true);
		this->saveToUprootListButton->setEnabled(true);
		this->openUprootListButton->setEnabled(true);
		this->filterPlantsButton->setEnabled(true);*/
		this->controller.SetMode(string("B"));
	}
	else if(this->mode == "B")
	{
		this->mode = "A";
		this->addPlantButton->setEnabled(true);
		this->removePlantButton->setEnabled(true);
		this->updatePlantButton->setEnabled(true);
		this->undoButton->setEnabled(true);
		this->redoButton->setEnabled(true);
		this->resetView->setEnabled(true);
		this->switchMode->setEnabled(true);
		/*this->nextButton->setEnabled(false);
		this->saveToUprootListButton->setEnabled(false);
		this->openUprootListButton->setEnabled(false);
		this->filterPlantsButton->setEnabled(false);*/
		this->controller.SetMode(string("A"));

	}
	if(this->mylistype == "memory")
		this->openUprootListButton->setEnabled(false);

	if (this->mode == "B")
	{
		MyListViewModel* model = new MyListViewModel{ this->controller };
		MyListWindow* window = new MyListWindow{ model,this->controller, this };

		window->show();
	}
	emit plantsUpdateSignal();
}

void PlantsGUI::executeRedoSlot()
{
	this->executeRedo();
}

void PlantsGUI::executeUndoSlot()
{
	this->executeUndo();
}


void PlantsGUI::AddPlant(const std::string& codeName, const std::string& species, const int ageInMonths, const std::string& digitizedScan)
{
	try {
		this->controller.AddNewPlant(codeName, species, ageInMonths, digitizedScan);
	}
	catch (RepositoryException& excep)
	{
		QMessageBox::critical(this, "My application", excep.what());
		return;
	}
	// emit the signal: the plants were updated
	emit plantsUpdateSignal();
}



void PlantsGUI::RemovePlant(const std::string& plantCodeName)
{
	try
	{
		this->controller.DeletePlant(plantCodeName);
	}
	catch (RepositoryException& excep)
	{
		QMessageBox::critical(this, "My application", excep.what());
		return;
	}

	emit plantsUpdateSignal();
}

void PlantsGUI::UpdatePlant(const std::string & plantCodeName, const std::string & species, const int ageInMonths, const std::string & digitizedScan)
{
	try
	{
		this->controller.UpdatePlant(plantCodeName, species, ageInMonths, digitizedScan);
	}
	catch (RepositoryException& excep)
	{
		QMessageBox::critical(this, "My application", excep.what());
		return;
	}

	emit plantsUpdateSignal();
}

void PlantsGUI::SaveToUprootList(const std::string & codeName)
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
	emit uprootUpdateSignal();
}

void PlantsGUI::FilterPlants(const std::string & species, const int ageInMonths)
{
	vector<Plant> filteredPlants= this->controller.displayPlantClutersByAgeAndSpecies(species, ageInMonths);
	this->populatePlantsListWithVector(filteredPlants);
}

void PlantsGUI::OpenUprootList()
{
	this->controller.displayChosenPlantClusters();
	return;
}
