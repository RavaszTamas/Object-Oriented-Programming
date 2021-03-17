#include "Controller.h"
#include <algorithm>

using namespace std;

Controller::Controller(IdeaRepository& _repo) :repo{ _repo }
{
}

std::vector<Idea> Controller::getAll()
{

	auto elements = this->repo.readAll();
	sort(elements.begin(), elements.end(), [](const Idea& idea1, const Idea& idea2) {return idea1.getAct() < idea2.getAct(); });
	return elements;
}

void Controller::saveToFile(std::string description, std::string status, std::string creator, std::string act)
{
	Idea newIdea{ description,status,creator,stoi(act) };
	this->repo.saveToFile(newIdea);

}

bool Controller::modifyStatus(std::string desc, int act)
{
	auto elements = this->repo.readAll();
	for (auto it = elements.begin(); it != elements.end(); ++it)
	{
		if (desc == it->getDesc() && act == it->getAct())
		{
			it->setStatus("accepted");
			this->repo.saveToFile(elements);
			return true;
		}
	}
	return false;
}

void Controller::savePlot()
{
	this->repo.createPlot();
}


Controller::~Controller()
{
}
