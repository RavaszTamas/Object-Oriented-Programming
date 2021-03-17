#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab11.h"
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "Domain.h"
#include "Service.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QRadioButton>
#include <QShortcut>

using namespace QtCharts;

class PlantsGUI : public QMainWindow
{
	Q_OBJECT

public:
	PlantsGUI(string mylistType,AppController& _paramController,QWidget *parent = 0);
	~PlantsGUI();

	string mode = "A";
	string mylistype;
	QListWidget* plantList;
	QListWidget* uprootPlantList;
	QLineEdit* codeNameEdit;
	QLineEdit* speciesEdit;
	QLineEdit* ageInMonthEdit;
	QLineEdit* digitizedScanEdit;
	QPushButton* addPlantButton;
	QPushButton* removePlantButton;
	QPushButton* updatePlantButton;
	QPushButton* filterPlantsButton;
	QPushButton* saveToUprootListButton;
	QPushButton* openUprootListButton;
	QPushButton* resetView;
	QPushButton* undoButton;
	QPushButton* redoButton;

	QShortcut* CTRLZ;
	QShortcut* CTRLY;

	QTabWidget* tabWidget;
	QWidget *tabOne;
	QWidget *tabTwo;
	QBarSet* setOfValues;
	QBarSeries* seriesOfValues;
	QChart* chartOfPlants;
	QStringList speciesNames;
	QBarCategoryAxis* axis;
	QChartView* chartView;
	QPushButton* switchMode;
	QPushButton* nextButton;
	void buildWindow();

	void connectSignalsAndSlots();

	void populatePlantsList();

	void populateUprootList();

	void populatePlantsListWithVector(std::vector<Plant> plants);

	void listItemChanged();

	int getSelectedIndex();

	void addPlantButtonHandler();

	void removePlantButonHandler();

	void updatePlantButtonHandler();

	void filterPlantsButtonHandler();

	void saveToUprootListButtonHandler();

	void openUprootListHandler();

	bool verifyNoSpaces();

	void switchModeAction();


	void reset();
	void nextItem();

	void executeUndo();
	void executeRedo();

signals:
	void plantsUpdateSignal();
	void uprootUpdateSignal();

	void RemovePlantSignal(const std::string& codeName);
	void AddPlantSignal(const std::string& codeName, const std::string& species, const int ageInMonths, const std::string& digitizedScan);
	void UpdatePlantSignal(const std::string& codeName, const std::string& species, const int ageInMonths, const std::string& digitizedScan);
	void SaveToUprootListSignal(const std::string& codeName);
	void FilterPlantsSignal(const std::string& species, const int ageInMonths);
	void OpenUprootListSignal();

public slots:
	void executeUndoSlot();
	void executeRedoSlot();
	void AddPlant(const std::string& plantCodeName, const std::string& species, const int ageInMonths, const std::string& digitizedScan);
	void RemovePlant(const std::string& plantCodeName);
	void UpdatePlant(const std::string& plantCodeName, const std::string& species, const int ageInMonths, const std::string& digitizedScan);
	void SaveToUprootList(const std::string& codeName);
	void FilterPlants(const std::string& species, const int ageInMonths);
	void OpenUprootList();

private:
	AppController& controller;
	Ui::Lab11Class ui;
};
