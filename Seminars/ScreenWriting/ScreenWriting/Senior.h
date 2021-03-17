#pragma once

#include <QWidget>
#include "ui_Senior.h"
#include <qabstractitemmodel.h>
#include "Controller.h"
#include "IdeasModel.h"

class Senior : public QWidget
{
	Q_OBJECT
public:
	Senior(Controller& _controller, IdeasModel* _model,std::string _name, QWidget *parent = Q_NULLPTR);
	~Senior();

private:
	Ui::Senior ui;
	std::string name;
	IdeasModel* model;
	Controller& controller;
	void addNew();
	void developAccepted();
	void acceptNewIdea();
	void savePlot();
	void checkForDevelop();
};
