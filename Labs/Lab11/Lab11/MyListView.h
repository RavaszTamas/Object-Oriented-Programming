#pragma once

#include <QAbstractListModel>
#include <QAbstractTableModel>
#include "FileManagersMyList.h"
#include "Service.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QListView>
#include <QTableView>
#include <QFormLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "gui.h"
#include <QShortcut>
#include "PictureDelegate.h"

class MyListViewModel : public QAbstractTableModel
{
private:
	AppController& controller;
	int loadedRows;
public:
	MyListViewModel(AppController& controller, QObject* parent = NULL);
	~MyListViewModel();

	int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
	int columnCount(const QModelIndex &parent = QModelIndex{}) const override;
	void resetModel();

	// Value at a given position
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

};

class MyListWindow : public QWidget
{
	Q_OBJECT

private:
	AppController& controller;
	QHBoxLayout *horizontalLayout;
	QTableView *tableView;
	QListWidget* listViewWidget;
	QLineEdit* codeNameEdit;
	QLineEdit* speciesEdit;
	QLineEdit* ageInMonthEdit;
	QLineEdit* digitizedScanEdit;
	QPushButton* filterPlantsButton;
	QPushButton* saveToUprootListButton;
	QPushButton* openUprootListButton;
	QPushButton* nextButton;
	QPushButton* redoButton;
	QPushButton* undoButton;
	QShortcut* CTRLZ;
	QShortcut* CTRLY;

	PlantsGUI* originalGUI;

	void setupUi(QWidget *TeacherWindow)
	{
		if (TeacherWindow->objectName().isEmpty())
			TeacherWindow->setObjectName(QStringLiteral("TeacherWindow"));
		TeacherWindow->resize(568, 379);


		
		horizontalLayout = new QHBoxLayout(TeacherWindow);
		horizontalLayout->setSpacing(6);
		horizontalLayout->setContentsMargins(11, 11, 11, 11);
		horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

		tableView = new QTableView(TeacherWindow);
		tableView->setObjectName(QStringLiteral("tableView"));

		QWidget* rightSide = new QWidget{};

		QVBoxLayout* rightColumn = new QVBoxLayout{ rightSide };

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

		QWidget* buttonsWidget = new QWidget{};
		QGridLayout* gridButtons = new QGridLayout{ buttonsWidget };


		this->filterPlantsButton = new QPushButton{ "Filter Plants" };
		this->filterPlantsButton->setFont(font);

		this->saveToUprootListButton = new QPushButton{ "Save plant" };
		this->saveToUprootListButton->setFont(font);

		this->openUprootListButton = new QPushButton{ "Open uproot list" };
		this->openUprootListButton->setFont(font);


		this->nextButton = new QPushButton{ "Next" };
		this->nextButton->setFont(font);

		this->undoButton = new QPushButton{ "Undo" };
		this->undoButton->setFont(font);

		this->redoButton = new QPushButton{ "Redo" };
		this->redoButton->setFont(font);

		
		gridButtons->addWidget(this->nextButton, 0, 0);
		gridButtons->addWidget(this->saveToUprootListButton, 0, 1);
		gridButtons->addWidget(this->openUprootListButton, 0, 2);
		gridButtons->addWidget(this->undoButton, 1, 0);
		gridButtons->addWidget(this->redoButton, 1, 1);
		gridButtons->addWidget(this->filterPlantsButton, 1, 2);

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

		this->listViewWidget = new QListWidget{};
		// set the selection model
		this->listViewWidget->setSelectionMode(QAbstractItemView::SingleSelection);
		horizontalLayout->addWidget(this->listViewWidget);


		horizontalLayout->addWidget(tableView);
		horizontalLayout->addWidget(tableView);
		rightColumn->addWidget(plantDataWidget);
		rightColumn->addWidget(buttonsWidget);
		horizontalLayout->addWidget(rightSide);

	}

	MyListViewModel* model;

	void filterPlantsButtonHandler();

	void saveToUprootListButtonHandler();

	void openUprootListHandler();

	void nextItem();

	void executeUndo();

	void executeRedo();

	bool verifyNoSpaces();

	void populateFilterList(std::vector<Plant> plants);

	void closeEvent(QCloseEvent *event) override;
	void connectSlots();
public:
	MyListWindow(MyListViewModel* model, AppController& controller, PlantsGUI* _originalGUI, QWidget *parent = Q_NULLPTR);
	~MyListWindow();

signals:
	void SaveToUprootListSignal(const std::string& codeName);
	void FilterPlantsSignal(const std::string& species, const int ageInMonths);
	void OpenUprootListSignal();
	void uprootUpdateSignal();

public slots:
	void executeUndoSlot();
	void executeRedoSlot();
	void SaveToUprootList(const std::string& codeName);
	void FilterPlants(const std::string& species, const int ageInMonths);
	void OpenUprootList();

};

