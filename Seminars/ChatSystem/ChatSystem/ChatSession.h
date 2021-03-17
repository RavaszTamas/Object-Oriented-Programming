#pragma once
#include "Observer.h"
#include <iostream>
#include <vector>

class ChatSession:public Subject
{
private:
	std::vector<std::pair<std::string, std::string>> messages;
public:
	void addMessage(std::string User, std::string Message);
	std::vector<std::pair<std::string, std::string>> getMessages();

};