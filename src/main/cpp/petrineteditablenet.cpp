#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>
#include "petrinet.h"
#include "petrinet_objects.h"
#include "petrinet_elements.h"

PetriNetEditableNet::PetriNetEditableNet()
    : QWidget()
{
    QVBoxLayout *lay = new QVBoxLayout();
    gs = new PNGraphicsScene(0,0,1920,1080, this);
    QGraphicsView *gv = new QGraphicsView(gs, this);
    lay->addWidget(gv);
    this->setLayout(lay);
}

void PetriNetEditableNet::addNewBasicPlace()
{
    PNBasicPlace *p = new PNBasicPlace(10,10);
    gs->addItem(p);
}


