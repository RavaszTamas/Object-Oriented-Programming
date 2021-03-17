#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Task
{
private:
	std::string description;
	std::string status;
	int id;
public:
	Task(std::string _description, std::string _status, int _id) :description{ _description }, status{ _status }, id{ _id } {}

	bool operator!=(Task other);

	int getId()const { return id; }
	std::string getStatus()const { return status; }
	std::string getDescription()const { return description; }
	void setStatus(std::string newStatus) { this->status = newStatus; }
	void setId(int newId) { id = newId; }

};

class Programmer
{
private:
	int id;
	std::string name;
public:
	Programmer(std::string _name, int _id) :name{ _name }, id{ _id } {}
	int getId()const { return id; }
	std::string getName()const { return name; }

};