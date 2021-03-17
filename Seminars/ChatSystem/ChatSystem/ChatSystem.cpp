#include "ChatSystem.h"
#include <ctime>
#include <sstream>

ChatSystem::ChatSystem(ChatSession& _paramRepo, std::string userName,QWidget *parent)
	: QMainWindow(parent), repo{ _paramRepo }, user{ userName }
{
	ui.setupUi(this);

	this->setWindowTitle(QString::fromStdString(userName));

	repo.addObserver(this);
	QRegExp rx("[^\ ].*");
	QRegExpValidator* v = new QRegExpValidator(rx, 0);
	ui.lineEdit->setValidator(v);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &ChatSystem::sendMessage);

}

void ChatSystem::sendMessage()
{
	if (ui.lineEdit->text().toStdString() == "")
	{
		return;
	}
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	std::stringstream ss;
	ss << (timePtr->tm_mday) << "/" << (timePtr->tm_mon) + 1 << "/" << (timePtr->tm_year) + 1900;
	ss << "/" << (timePtr->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec);

	std::pair<std::string, std::string> mesg = { this->user , ui.lineEdit->text().toStdString() };
	this->repo.addMessage(mesg.first,mesg.second);
	ui.lineEdit->clear();
}

void ChatSystem::update()
{
	auto allMessages = this->repo.getMessages();

	ui.listWidget->clear();
	for (auto iter : allMessages)
	{
		if (iter.first == this->user)
		{
			QString str = QString::fromStdString(iter.second);
			QListWidgetItem* item = new QListWidgetItem{ str };
			item->setTextAlignment(Qt::AlignRight);
			ui.listWidget->addItem(item);
		}
		else
		{
			QString str = QString::fromStdString(iter.first + ": " + iter.second);
			QListWidgetItem* item = new QListWidgetItem{ str };
			item->setTextAlignment(Qt::AlignLeft);
			ui.listWidget->addItem(item);

		}
	}
}
