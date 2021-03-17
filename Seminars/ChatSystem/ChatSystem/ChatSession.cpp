#include "ChatSession.h"

void ChatSession::addMessage(std::string User, std::string Message)
{
	this->messages.push_back(std::pair<std::string, std::string>{User,Message});
	this->notify();
}

std::vector<std::pair<std::string, std::string>> ChatSession::getMessages()
{
	return this->messages;
}
