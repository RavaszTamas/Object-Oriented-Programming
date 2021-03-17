#pragma once

#include <QWidget>
#include "ui_TeacherWindow.h"
#include "MyModel.h"

class TeacherWindow : public QWidget
{
	Q_OBJECT

private:
	QAbstractItemModel* model;

public:
	TeacherWindow(QAbstractItemModel* m, QWidget *parent = Q_NULLPTR);
	~TeacherWindow();

private:
	Ui::TeacherWindow ui;
};
