#pragma once
#include "Repository.h"
class Controller
{
private:
	Repository& repo;
public:
	Controller(Repository& _repo) :repo{ _repo } {};
	std::vector<Idea> getAll();
	void addElement(std::string description, std::string status, std::string creator, std::string act);
	void acceptIdea(std::string description, std::string status, std::string creator, std::string act);
	bool checkForDevelopment(std::string creator);
	~Controller();
};

