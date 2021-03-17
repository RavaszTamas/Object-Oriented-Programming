#include "ScreenWriting.h"
#include <QtWidgets/QApplication>
#include "IdeasModel.h"
#include "IdeaRepository.h"
#include "Controller.h"
#include <fstream>
#include "Assistant.h"
#include "Junior.h"
#include "Senior.h"
#include <string>
#include "IdeasModel.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IdeaRepository repo;
	Controller controller{ repo };
	IdeasModel model{ controller };

	ifstream input{ "screenwriters.txt" };
	string line;
	while (getline(input, line))
	{
		if (line == "")
			continue;
		auto params = tokenize(line, ' ');
		int first = params[0].find_first_not_of(' ');
		int last = params[0].find_last_not_of(' ');
		params[0] = params[0].substr(first, last - first + 1);
		first = params[1].find_first_not_of(' ');
		last = params[1].find_last_not_of(' ');
		params[1] = params[1].substr(first, last - first + 1);

		if (params[1] == "Assistant")
		{
			Assistant* newA = new Assistant{controller,&model,params[0]};
			newA->show();
		}
		else if (params[1] == "Junior")
		{
			Junior* newJ = new Junior{ controller, &model,params[0] };
			newJ->show();
		}
		else if (params[1] == "Senior")
		{
			Senior* newS = new Senior{ controller, &model,params[0] };
			newS->show();
		}

	}

	return a.exec();
}
