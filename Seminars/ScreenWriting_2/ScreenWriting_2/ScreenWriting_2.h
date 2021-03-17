#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ScreenWriting_2.h"
#include "Controller.h"
#include "IdeaModel.h"
#include "TextEditor.h"

class ScreenWriting_2 : public QMainWindow
{
	Q_OBJECT

public:
	ScreenWriting_2(Controller& controller,IdeaModel* model,std::string _name, std::string _rank,QWidget *parent = Q_NULLPTR);

private:
	Controller& controller;
	IdeaModel* model;
	std::string name;
	std::string rank;
	Ui::ScreenWriting_2Class ui;
	void uiAddNew();
	void acceptIdea();
	void checkForDevelop();
	void openDevelopment();
	void doStuff();
};
