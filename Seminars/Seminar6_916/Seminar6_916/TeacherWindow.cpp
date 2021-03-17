#include "TeacherWindow.h"

TeacherWindow::TeacherWindow(QAbstractItemModel* m, QWidget *parent)
	: QWidget(parent), model{ m }
{
	ui.setupUi(this);

	this->ui.tableView->setModel(this->model);
}

TeacherWindow::~TeacherWindow()
{
}
