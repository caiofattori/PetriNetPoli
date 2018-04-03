
#include<QtCore/QState>
#include <QtWidgets/QStatusBar>
#include "petrinet.h"
#include "petrinet_utils.h"

PetriNetStateIdle::PetriNetStateIdle()
    :QState()
{

}

void PetriNetStateIdle::onEntry(QEvent *event)
{
    PetriNetStMach *m  = (PetriNetStMach *) this->machine();
    if(this == m->idle_shift){
        m->window->statusBar()->showMessage("Idle S");
    }
    else{
        m->window->statusBar()->showMessage("Idle");
    }
}

void PetriNetStateIdle::onExit(QEvent *event)
{
}
