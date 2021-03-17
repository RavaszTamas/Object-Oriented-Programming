#include "Controller.h"
#include <algorithm>



std::vector<Idea> Controller::getAll()
{
	auto elements = this->repo.readAll();

	std::sort(elements.begin(), elements.end(), [](Idea ideaOne, Idea ideaTwo) {return ideaOne.getAct() < ideaTwo.getAct(); });

	return elements;
}

void Controller::addElement(std::string description, std::string status, std::string creator, std::string act)
{
	Idea newidea{ description,status,creator,act };
	this->repo.addNew(newidea);
}

void Controller::acceptIdea(std::string description, std::string status, std::string creator, std::string act)
{
	Idea idea{ description,status,creator,act };
	this->repo.acceptIdea(idea);
}

bool Controller::checkForDevelopment(std::string creator)
{
	auto elements = this->repo.readAll();
	for (auto it : elements)
		if (it.getCreator() == creator && it.getStatus() == "accepted")
			return true;
	return false;
}

Controller::~Controller()
{
}
