#pragma once

#include <QtWidgets/QWidget>
#include <ActiveQt/QAxBindable>

#include "ui_ChatWindowStuff.h"

class ChatWindowStuff : public QWidget, public QAxBindable
{
	Q_OBJECT

public:
	ChatWindowStuff(QWidget *parent = Q_NULLPTR);

private:
	Ui::ChatWindowStuffClass ui;
};
