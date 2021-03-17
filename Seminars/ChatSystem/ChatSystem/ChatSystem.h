#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatSystem.h"
#include "Observer.h"
#include "ChatSession.h"

class ChatSystem : public QMainWindow , public Observer
{
	Q_OBJECT

public:
	ChatSystem(ChatSession& _paramRepo,std::string userName,QWidget *parent = Q_NULLPTR);
	void sendMessage();
	void update() override;

private:
	std::string user;
	ChatSession& repo;
	Ui::ChatSystemClass ui;
};
