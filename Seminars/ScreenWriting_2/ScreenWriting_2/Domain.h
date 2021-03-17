#pragma once
#include <string>
class Idea
{
private:
	std::string description;
	std::string act;
	std::string creator;
	std::string status;
public:
	Idea(std::string _description, std::string _status, std::string _creator, std::string _act) :description{ _description }, act{ _act }, creator{ _creator }, status{ _status } {}
	std::string getDescription() const { return description; }
	std::string getAct()const { return act; }
	std::string getCreator()const { return creator; }
	std::string getStatus()const { return status; }
	void setDescription(std::string newVal) {
		description = newVal;
	}
	void setAct(std::string newVal) {
		act = newVal;
	}
	void setCreator(std::string newVal) {
		creator = newVal;
	}
	void setStatus(std::string newVal) {
		status = newVal;
	}
	bool operator==(const Idea& other) const;
};

class ScreenWriter
{
private:
	std::string name;
	std::string rank;
public:
	ScreenWriter(std::string _name, std::string _rank) :name{ _name }, rank{ _rank } {}
	std::string getName()const {
		return name;
	}
	std::string getRank()const {
		return rank;
	}

};