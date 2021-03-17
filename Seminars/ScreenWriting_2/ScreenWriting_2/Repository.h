#pragma once
#include <vector>
#include "Domain.h"

std::vector<std::string> tokenize(std::string line, const char delimiter);

class Repository
{
private:
	std::vector<Idea> ideas;
	std::string filename;
	std::string screenwriters;
public:
	Repository(std::string _filename, std::string _screenw) :filename{ _filename }, screenwriters{_screenw} {}
	std::vector<Idea> readAll();
	std::vector<ScreenWriter> readAllWriters();
	void writeAll(std::vector<Idea> elements);
	void addNew(Idea newIea);
	void acceptIdea(Idea newIea);
	
	~Repository();
};

