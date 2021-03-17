#include "Repository.h"
#include <sstream>
#include <exception>


using namespace std;

const char* RepositoryException::what() const noexcept
{
	return message_error.c_str();
}

Repository::Repository(std::string _filenameProgrammer, std::string _filenameTasks) :filenameProgrammer{ _filenameProgrammer }, filenameTasks{ _filenameTasks }
{
	this->readTasks();
}

std::vector<Programmer> Repository::getProgrammers()
{
	ifstream input{ this->filenameProgrammer };
	string line;
	vector<Programmer> result;
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
		Programmer auxprog{ params[0],std::stoi(params[1] )};
		result.push_back(auxprog);
	}
	return result;
}

std::vector<Task> Repository::getTasks()
{
	return this->tasks;
}

void Repository::storeTask(Task newTask)
{
	this->tasks.push_back(newTask);
}

void Repository::deleteTask(Task oldTask)
{
	auto iter = tasks.begin();
	for (; iter != tasks.end() && *iter != oldTask; ++iter);

	if (iter != tasks.end())
	{
		this->tasks.erase(iter);
	}
}

void Repository::activateTask(std::string description, int id)
{
	auto iter = tasks.begin();
	for (; iter != tasks.end() && (iter->getDescription() != description || iter->getStatus() != "open"); ++iter);

	if (iter == tasks.end())
		throw RepositoryException("Invalid task to acivate!");

	iter->setStatus("in progress");
	iter->setId(id);
}

void Repository::finishTask(std::string description, int id)
{
	auto iter = tasks.begin();
	for (; iter != tasks.end() && (iter->getDescription() != description || iter->getStatus() != "in progress"); ++iter);

	if (iter == tasks.end())
		return;
	iter->setStatus("closed");
	iter->setId(id);
}

void Repository::readTasks()
{
	ifstream input{ this->filenameTasks };
	string line;
	vector<Task> result;
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
		first = params[2].find_first_not_of(' ');
		last = params[2].find_last_not_of(' ');
		params[2] = params[2].substr(first, last - first + 1);

		Task auxprog{ params[0],params[1],stoi(params[2]) };
		result.push_back(auxprog);
	}
	this->tasks = result;
	//return result;
}


Repository::~Repository()
{
	ofstream output{ this->filenameTasks };
	for (auto it : tasks)
	{
		output << it.getDescription() << "|" << it.getStatus() << "|" << it.getId() << endl;
	}
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
