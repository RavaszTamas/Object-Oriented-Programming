#pragma once

#include <QtWidgets/QMainWindow>
#include <qlistwidget.h>
#include "ui_Proxy.h"
#include "Controller.h"
#include "Patient.h"

class Proxy : public QMainWindow
{
	Q_OBJECT

public:
	Proxy(Controller& s, QWidget *parent = Q_NULLPTR);

private:
	Ui::ProxyClass ui;

	Controller& ctrl;
	void populatePatientsList();
	void populateStudyList(Patient& p);

	int getListSelectedIndex(QListWidget*);
	Patient& getCurrentPatient();

	void patientsListItemChanged();
	void imagesListItemChanged();
};
