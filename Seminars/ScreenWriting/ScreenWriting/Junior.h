#pragma once

#include <QWidget>
#include "ui_Junior.h"
#include "Controller.h"
#include "IdeasModel.h"

class Junior : public QWidget
{
	Q_OBJECT

public:
	Junior(Controller& _controller, IdeasModel* _model,std::string _name, QWidget *parent = Q_NULLPTR);
	~Junior();

private:
	Ui::Junior ui;
	std::string name;
	IdeasModel* model;
	Controller& controller;
	void developAccepted();
	void addNew();
	void savePlot();
	void checkForDevelop();
};
