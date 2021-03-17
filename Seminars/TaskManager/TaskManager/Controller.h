#pragma once
#include "Repository.h"
#include "Subject.h"

class Controller:public Subject
{
private:
	Repository& repo;
public:
	Controller(Repository& _repo);
	std::vector<Programmer> getAllProgrammers();
	std::vector<Task> getAllTasks();
	void addTask(std::string description, std::string name);
	/*
	Deletes a task having these properties from the repository
	input description - description of task
			status - the status of the task
			id - the id of the programmer
	output none
	*/
	void removeTask(std::string description, std::string status,int id);
	/*
	Sets the status of the task with a given description and user to closed if it is open
	input description - description of task
	name - name of the programmer executing the task
	output none
	*/

	void beginTask(std::string description,std::string name);
	/*
	Sets the status of the task with a given description and user to closed if it is in progress
	input description - description of task
	name - name of the programmer executing the task
	output none
	*/
	void finishTask(std::string description, std::string name);
	int getIdOfName(std::string name);
	std::string getNameOfId(int id);
	~Controller();
};

