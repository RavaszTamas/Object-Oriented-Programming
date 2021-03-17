#pragma once
#include <string>

class Idea
{
private:
	std::string desc;
	std::string status;
	std::string creator;
	int act;
public:
	Idea() {}
	Idea(std::string paramdesc, std::string paramstatus, std::string paramcreator, int paramact) :desc{ paramdesc }, status{ paramstatus }, creator{ paramcreator }, act{ paramact } {}
	std::string getDesc() const {
		return desc;
	}
	std::string getCreator() const {
		return creator;
	}
	std::string getStatus() const {
		return status;
	}
	int getAct() const {
		return act;
	}
	void setStatus(std::string newVal)
	{
		status = newVal;
	}
};