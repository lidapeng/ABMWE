#include "abmwe.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ABMWE w;
	w.setWindowTitle("Agent-based DSS for Wildfire Evacuation");
	w.show();
	
	return a.exec();
}
