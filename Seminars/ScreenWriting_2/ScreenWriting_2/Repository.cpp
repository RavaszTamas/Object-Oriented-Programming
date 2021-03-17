#include "Repository.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


std::vector<Idea> Repository::readAll()
{
	std::ifstream input(this->filename);
	string line;
	vector<Idea> result;
	while (getline(input, line))
	{
		if (line == "")
			continue;
		auto params = tokenize(line,'|');
		int first = params[0].find_first_not_of(' ');
		int last = params[0].find_last_not_of(' ');
		params[0] = params[0].substr(first, last - first + 1);

		first = params[1].find_first_not_of(' ');
		last = params[1].find_last_not_of(' ');
		params[1] = params[1].substr(first, last - first + 1);

		first = params[2].find_first_not_of(' ');
		last = params[2].find_last_not_of(' ');
		params[2] = params[2].substr(first, last - first + 1);

		first = params[3].find_first_not_of(' ');
		last = params[3].find_last_not_of(' ');
		params[3] = params[3].substr(first, last - first + 1);
		result.push_back(Idea{ params[0],params[1],params[2],params[3] });


	}
	return result;
}

std::vector<ScreenWriter> Repository::readAllWriters()
{
	std::ifstream input(this->screenwriters);
	string line;
	vector<ScreenWriter> result;
	while (getline(input, line))
	{
		if (line == "")
			continue;
		auto params = tokenize(line, '|');
		int first = params[0].find_first_not_of(' ');
		int last = params[0].find_last_not_of(' ');
		params[0] = params[0].substr(first, last - first + 1);

		first = params[1].find_first_not_of(' ');
		last = params[1].find_last_not_of(' ');
		params[1] = params[1].substr(first, last - first + 1);
		result.push_back(ScreenWriter{ params[0],params[1] });


	}
	return result;

}

void Repository::writeAll(std::vector<Idea> elements)
{
	ofstream output{ this->filename };
	for (auto it : elements)
	{
		output << it.getDescription() << '|' << it.getStatus() << '|' << it.getCreator() << '|' << it.getAct() << endl;
	}
}

void Repository::addNew(Idea newIea)
{
	auto elements = this->readAll();

	for (auto it : elements)
		if (it.getDescription() == newIea.getDescription() && it.getAct() == newIea.getAct())
			throw exception("Program already exists!");
	elements.push_back(newIea);
	this->writeAll(elements);
}

void Repository::acceptIdea(Idea idea)
{
	auto elements = this->readAll();
	bool good = true;
	for (auto it = elements.begin(); good && it != elements.end(); ++it)
	{
		if (idea == *it)
		{
			good = false;
			it->setStatus("accepted");
		}
	}
	this->writeAll(elements);

}

	Repository::~Repository()
{
}

std::vector<std::string> tokenize(std::string line, const char delimiter)
{
	stringstream ss{ line };
	string token;
	vector<string> tokens;
	while (getline(ss, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}
