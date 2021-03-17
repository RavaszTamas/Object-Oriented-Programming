#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ScreenWriting.h"

class ScreenWriting : public QMainWindow
{
	Q_OBJECT

public:
	ScreenWriting(QWidget *parent = Q_NULLPTR);

private:
	Ui::ScreenWritingClass ui;
};
