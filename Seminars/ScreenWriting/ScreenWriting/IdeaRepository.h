#pragma once
#include "Domain.h"
#include <vector>
#include <string>

std::vector<std::string> tokenize(std::string line, char delimiter);


class IdeaRepository
{
public:
	IdeaRepository();
	std::vector<Idea>readAll();
	void saveToFile(std::vector<Idea> ideas);
	void saveToFile(Idea idea);
	void createPlot();
	~IdeaRepository();
};

