#include <iostream>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>

#include "petrinet.h"


PetriNetWindow::PetriNetWindow()
{
	QWidget* wg = new QWidget;
	setCentralWidget(wg);
	QVBoxLayout* main_layout = new QVBoxLayout;
	wg->setLayout(main_layout);
}


