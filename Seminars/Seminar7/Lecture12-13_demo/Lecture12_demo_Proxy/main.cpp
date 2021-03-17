#include <qapplication.h>
#include "Controller.h"
#include "Proxy.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller ctrl{};
	Proxy w{ ctrl };
	w.showMaximized();
	return a.exec();
}
