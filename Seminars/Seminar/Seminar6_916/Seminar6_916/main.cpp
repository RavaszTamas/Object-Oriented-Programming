#include "Seminar6_916.h"
#include <QtWidgets/QApplication>
#include "TeacherWindow.h"
#include <QSortFilterProxyModel>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository repo{"Students.txt"};
	MyModel model{repo};

	TeacherWindow w1{&model};
	w1.show();

	QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
	proxyModel->setSourceModel(&model);

	proxyModel->setFilterRegExp(QRegExp("915", Qt::CaseInsensitive,
		QRegExp::FixedString));
	proxyModel->setFilterKeyColumn(1);

	TeacherWindow teacherForGroupWindow{ proxyModel };
	teacherForGroupWindow.setWindowTitle("Teacher for 915");
	teacherForGroupWindow.show();

	return a.exec();
}
