#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ScreenWritingTakeTwo.h"

class ScreenWritingTakeTwo : public QMainWindow
{
	Q_OBJECT

public:
	ScreenWritingTakeTwo(QWidget *parent = Q_NULLPTR);

private:
	Ui::ScreenWritingTakeTwoClass ui;
};
