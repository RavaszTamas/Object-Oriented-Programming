#include "TaskManager.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "programmers.txt","tasks.txt" };
	Controller controller{ repo };
	auto programmers = repo.getProgrammers();
	for (auto it = programmers.begin(); it != programmers.end(); ++it)
	{
		TaskManager* manager = new TaskManager{it->getName(),controller };
		manager->show();
	}
	return a.exec();
}
