#include "ChatWindowStuff.h"

#include <ActiveQt/QAxFactory>

ChatWindowStuff::ChatWindowStuff(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QAXFACTORY_DEFAULT(ChatWindowStuff,
	"{c39bfab3-8e69-446b-aba6-2ddd2c459c59}",
	"{55294eda-714f-44f3-ae61-03aba1f0f126}",
	"{e6aca053-09bf-4c22-8e72-6a42baed13d3}",
	"{0585f4f5-953a-46de-abc8-dbf9171dbfdb}",
	"{42974f70-4a6e-4eb0-aae7-4de5b30b43d5}"
)
