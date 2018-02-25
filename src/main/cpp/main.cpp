#include <QtWidgets/QApplication>

#include "petrinet.h"

int main(int argc, char **argv){
	QApplication app(argc, argv);

	PetriNetWindow mainwin;

	mainwin.show();
	return app.exec();
}
