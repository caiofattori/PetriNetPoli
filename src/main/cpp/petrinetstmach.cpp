
#include<QtCore/QStateMachine>
#include<QtCore/QState>
#include<QtWidgets/QKeyEventTransition>
#include<QtCore/QSignalTransition>
#include<QtCore/QObject>
#include<QtWidgets/QPushButton>
#include<QtCore/QEvent>
#include "petrinet.h"
#include "petrinet_utils.h"
#include "petrinet_objects.h"

PetriNetStMach::PetriNetStMach(PetriNetWindow *window, PetriNetEditableNet *view)
    :QStateMachine()
{
    idle = new PetriNetStateIdle();
    idle_shift = new PetriNetStateIdle();
    inserting = new PetriNetStateInserting();
    inserting_shift = new PetriNetStateInserting();
    this->window = window;
    this->view = view;

    this->addState(idle);
    this->addState(idle_shift);
    this->addState(inserting);
    this->addState(inserting_shift);
    idle->addTransition(window->btn_place, SIGNAL(clicked()), inserting);
    inserting->addTransition(window->btn_place, SIGNAL(clicked()), idle);
    inserting->addTransition(view->gv, SIGNAL(mouseLeftClick()), idle);
    idle_shift->addTransition(window->btn_place, SIGNAL(clicked()), inserting_shift);
    inserting_shift->addTransition(window->btn_place, SIGNAL(clicked()), idle_shift);


    this->createShiftTransition(idle, idle_shift);
    this->createShiftTransition(inserting, inserting_shift);
    this->setInitialState(idle);
    currentState = PetriNetStMach::IDLE;
    //window->statusBar()
}

void PetriNetStMach::setState(Mstate s)
{
    currentState = s;
}

PetriNetStMach::Mstate PetriNetStMach::getState()
{
    return currentState;
}

void PetriNetStMach::createShiftTransition(QState *s1, QState *s2)
{
    QKeyEventTransition *shift = new QKeyEventTransition(this->window, QEvent::KeyPress, Qt::Key_Shift);
    shift->setTargetState(s2);
    s1->addTransition(shift);
    QKeyEventTransition *unshift = new QKeyEventTransition(this->window, QEvent::KeyRelease, Qt::Key_Shift);
    unshift->setTargetState(s1);
    s2->addTransition(unshift);
}
