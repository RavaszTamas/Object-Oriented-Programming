#include "IdeaRepository.h"
#include <fstream>
#include <string>
#include <sstream>
#include <exception>
#include <algorithm>

using namespace std;

IdeaRepository::IdeaRepository()
{
}

std::vector<std::string> tokenize(string line, char delimiter)
{
	vector <string> result;
	stringstream ss(line);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

std::vector<Idea> IdeaRepository::readAll()
{
	ifstream input("ideas.txt");
	string line;
	vector<Idea> ideas;
	while (getline(input, line))
	{
		if (line == "")
			continue;
		auto params = tokenize(line, ' ');
		int first = params[0].find_first_not_of(' ');
		int last = params[0].find_last_not_of(' ');
		params[0] = params[0].substr(first, (last - first + 1));

		first = params[1].find_first_not_of(' ');
		last = params[1].find_last_not_of(' ');
		params[1] = params[1].substr(first, (last - first + 1));

		first = params[2].find_first_not_of(' ');
		last = params[2].find_last_not_of(' ');
		params[2] = params[2].substr(first, (last - first + 1));

		first = params[3].find_first_not_of(' ');
		last = params[3].find_last_not_of(' ');
		params[3] = params[3].substr(first, (last - first + 1));

		Idea auxilliary{ params[0],params[1],params[2],stoi(params[3]) };
		ideas.push_back(auxilliary);

	}
	return ideas;
}

void IdeaRepository::saveToFile(vector<Idea> ideas)
{
	ofstream output("ideas.txt");
	for (auto it : ideas)
	{
		output << it.getDesc() << " " << it.getStatus() << " " << it.getCreator() << " " << it.getAct() << endl;
	}
}

void IdeaRepository::saveToFile(Idea idea)
{
	auto elements = this->readAll();
	for (auto it : elements)
	{
		if (it.getAct() == idea.getAct() && it.getDesc() == idea.getDesc())
			throw exception{ "Already existing element!" };
	}
	elements.push_back(idea);
	ofstream output("ideas.txt");
	for (auto it : elements)
	{
		output << it.getDesc() << " " << it.getStatus() << " " << it.getCreator() << " " << it.getAct() << endl;
	}
}

void IdeaRepository::createPlot()
{
	auto elements = this->readAll();
	sort(elements.begin(), elements.end(), [](const Idea& idea1, const Idea& idea2) {return idea1.getAct() < idea2.getAct(); });
	ofstream out{ "saveplot.txt" };

	for (int act = 1; act <= 3; ++act)
	{
		out << "Act " << act << ":\n";
		for (auto it : elements)
		{
			if (it.getStatus() == "accepted" && act == it.getAct())
			{
				out << it.getDesc() << " (" << it.getCreator() << ")" << endl;
			}
		}
	}
}


IdeaRepository::~IdeaRepository()
{
}
