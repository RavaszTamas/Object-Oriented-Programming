#include "ScreenWriting_2.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Controller.h"
#include "IdeaModel.h"

int main(int argc, char *argv[])
{
	Repository repo{ "ideas.txt" ,"screenwriters.txt"};
	Controller controller{ repo };
	IdeaModel model{ controller };
	QApplication a(argc, argv);
	auto writers = repo.readAllWriters();
	for (auto it : writers)
	{

		ScreenWriting_2* w = new ScreenWriting_2{ controller,&model,it.getName(), it.getRank() };
		w->show();
	}
	return a.exec();
}
