#include "ChatSystem.h"
#include <QtWidgets/QApplication>
#include "ChatSession.h"
#include "ChatSystem.h"
#include "Observer.h"

int main(int argc, char *argv[])
{
	ChatSession session{};
	QApplication a(argc, argv);
	ChatSystem w1{ session, "Peter" };
	ChatSystem w2{ session, "Joe" };
	ChatSystem w3{ session, "Martin" };

	w1.show();
	w2.show();
	w3.show();

	return a.exec();
}
