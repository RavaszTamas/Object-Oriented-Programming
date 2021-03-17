#pragma once

#include <QWidget>
#include "ui_Assistant.h"
#include "Controller.h"
#include "IdeasModel.h"
#include "TextEditor.h"

class Assistant : public QWidget
{
	Q_OBJECT

public:
	Assistant(Controller& _controller, IdeasModel* _model,std::string _name, QWidget*parent = Q_NULLPTR);
	~Assistant();

private:
	Ui::Assistant ui;
	std::string name;
	IdeasModel* model;
	Controller& controller;
	void developAccepted();
	void addNew();
	void savePlot();
	void checkForDevelop();
};
