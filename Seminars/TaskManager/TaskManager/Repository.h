#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Domain.h"
#include <vector>

std::vector<std::string> tokenize(std::string line, const char delimiter);

class RepositoryException :public std::exception
{
private:
	std::string message_error;
public:
	RepositoryException(std::string error) : message_error{ error } {};

	const char* what() const noexcept override;
};


class Repository
{
private:
	std::string filenameProgrammer;
	std::string filenameTasks;
	std::vector<Task> tasks;
	std::vector<Programmer> programmers;
public:
	Repository(std::string _filenameProgrammer,std::string _filenameTasks);
	std::vector<Programmer> getProgrammers();
	void readTasks();
	std::vector<Task> getTasks();
	void storeTask(Task newTask);
	/*
	Deletes a task having these properties from the repository
	input: oldTask the task to be deleted
	output: none
	*/

	void deleteTask(Task oldTask);
	/*
	Sets the status of the task with a given description and user to in progress if it open
	input description - description of task
	id - id of the programmer executing the task
	output none
	*/

	void activateTask(std::string description,int id);
	/*
	Sets the status of the task with a given description and user to closed if it is in progress
	input description - description of task
	id - id of the programmer executing the task
	output none
	*/

	void finishTask(std::string description, int id);
	~Repository();
};

