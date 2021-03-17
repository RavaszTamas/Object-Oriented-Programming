#pragma once
#include "IdeaRepository.h"

class Controller
{
private:
	IdeaRepository& repo;
public:
	Controller(IdeaRepository& _repo);
	std::vector<Idea> getAll();
	void saveToFile(std::string description, std::string status, std::string creator, std::string act);
	bool modifyStatus(std::string desc, int act);
	void savePlot();
	~Controller();
};

