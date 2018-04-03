
#include<QtCore/QState>
#include <QtWidgets/QStatusBar>
#include "petrinet.h"
#include "petrinet_utils.h"

PetriNetStateInserting::PetriNetStateInserting()
    :QState()
{

}

void PetriNetStateInserting::onEntry(QEvent *event)
{
    PetriNetStMach *m  = (PetriNetStMach *) this->machine();
    if(this == m->inserting_shift){
        m->window->statusBar()->showMessage("Inserting S");
    }
    else{
        m->window->statusBar()->showMessage("Inserting");
    }

}

void PetriNetStateInserting::onExit(QEvent *event)
{
}
