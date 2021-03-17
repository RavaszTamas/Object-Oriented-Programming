#include "Controller.h"
#include <algorithm>



Controller::Controller(Repository& _repo) :repo{ _repo }
{
}

std::vector<Programmer> Controller::getAllProgrammers()
{
	return this->repo.getProgrammers();
}

std::vector<Task> Controller::getAllTasks()
{
	auto tasks = this->repo.getTasks();
	std::sort(tasks.begin(), tasks.end(), [](Task one, Task two) {return one.getStatus() > two.getStatus(); });
	return tasks;
}

void Controller::addTask(std::string description, const std::string name)
{
	//auto prog = this->repo.getProgrammers();
	//auto iter = prog.begin();
	//for (; iter != prog.end() && iter->getName() != name;++iter)

	this->repo.storeTask(Task{ description,std::string("open"), -1 });
	this->notify();
}

void Controller::removeTask(std::string description, std::string status, int id)
{
	this->repo.deleteTask(Task{ description,status,id });
	this->notify();
}

void Controller::beginTask(std::string description, std::string name)
{
	auto prog = this->repo.getProgrammers();
	auto iter = prog.begin();
	for (; iter != prog.end() && iter->getName() != name; ++iter);

	this->repo.activateTask(description,iter->getId());
	this->notify();
}

void Controller::finishTask(std::string description, std::string name)
{
	auto prog = this->repo.getProgrammers();
	auto iter = prog.begin();
	for (; iter != prog.end() && iter->getName() != name; ++iter);

	this->repo.finishTask(description, iter->getId());
	this->notify();

}

int Controller::getIdOfName(std::string name)
{
	auto prog = this->repo.getProgrammers();
	auto iter = prog.begin();
	for (; iter != prog.end() && iter->getName() != name; ++iter);
	return iter->getId();
}

std::string Controller::getNameOfId(int id)
{
	auto prog = this->repo.getProgrammers();
	auto iter = prog.begin();
	for (; iter != prog.end() && iter->getId() != id; ++iter);
	return iter->getName();
}


Controller::~Controller()
{
}
