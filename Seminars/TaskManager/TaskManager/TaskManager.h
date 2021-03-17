#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManager.h"
#include "Controller.h"
#include "Observer.h"

class TaskManager : public QMainWindow,public Observer
{
	Q_OBJECT

public:
	TaskManager(std::string name,Controller& controller,QWidget *parent = Q_NULLPTR);

private:
	void update() override;
	void addTask();
	void removeTask();
	void startTask();
	void finishTask();
	void checkForItemInList();
	Controller& controller;
	Ui::TaskManagerClass ui;
	std::string name;
};
