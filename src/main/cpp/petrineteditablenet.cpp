#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>
#include "petrinet.h"
#include "petrinet_objects.h"
#include "petrinet_elements.h"
#include "petrinet_utils.h"

PetriNetEditableNet::PetriNetEditableNet(PetriNetWindow *win)
    : QWidget()
{
    this->win = win;
    QVBoxLayout *lay = new QVBoxLayout();
    gs = new PNGraphicsScene(0,0,1920,1080, this);
    gv = new PNGraphicsView(gs, this);
    stmach = new PetriNetStMach(win, this);
    stmach->start();
    lay->addWidget(gv);
    this->setLayout(lay);
}

void PetriNetEditableNet::showEvent(QShowEvent *event)
{
    delete stmach;
    stmach = new PetriNetStMach(this->win, this);
    stmach->start();
}

void PetriNetEditableNet::addNewBasicPlace()
{
    PNBasicPlace *p = new PNBasicPlace(10,10);
    gs->addItem(p);
}


