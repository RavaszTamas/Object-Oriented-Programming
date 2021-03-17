#include "gui.h"
#include <QtWidgets/QApplication>
#include "TextFileRepo.h"
#include "Service.h"
#include <fstream>

int main(int argc, char *argv[])
{
	ifstream configuration{ "config.txt" };
	string repoType;
	string myListType;
	if(configuration.fail())
		throw exception("NO CONFIGURATION FILE!");

	configuration >> repoType;
	PlantRepository* paramRepositroy;
	if (repoType == "memory")
	{
		paramRepositroy = new PlantRepositoryMemory{};

	}
	else if (repoType == "textfile")
	{
	
		paramRepositroy = new PlantFileRepository{};
	}
	else
	{
		throw exception("INVALID CONFIGURATION FILE!");
	}
	configuration >> myListType;
	if (myListType == "csv")
	{

	}
	else if (myListType == "html")
	{

	}
	else
	{
		throw exception("INVALID CONFIGURATION FILE!");
	}
	if (repoType == "memory")
		myListType = "memory";
	
	Validator validator;
	AppController controller{ *paramRepositroy, validator };

	QApplication a(argc, argv);
	PlantsGUI gui{ myListType, controller };
	gui.show();
	return a.exec();
}
