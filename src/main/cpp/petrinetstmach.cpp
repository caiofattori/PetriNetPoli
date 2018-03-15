#include "petrinet_utils.h"
#include<QtCore/QStateMachine>
#include<QtCore/QState>
#include<QtWidgets/QKeyEventTransition>
#include<QtCore/QSignalTransition>
#include "petrinet.h"

PetriNetStMach::PetriNetStMach(PetriNetWindow *window)
    :QStateMachine()
{
    idle = new QState();
    QState *idle_shift = new QState();
    inserting = new QState();
    QState *inserting_shift = new QState();
    this->window = window;

    this->addState(idle);
    this->addState(idle_shift);
    this->addState(inserting);
    this->addState(inserting_shift);
    QSignalTransition *place = new QSignalTransition(window->btn_place, SIGNAL(clicked()));
    place->setTargetState(inserting);
    idle->addTransition(place);
    QSignalTransition *unplace = new QSignalTransition(window->btn_place, SIGNAL(clicked()));
    unplace->setTargetState(idle);
    inserting->addTransition(unplace);
    this->createShiftTransition(idle, idle_shift);
    this->createShiftTransition(inserting, inserting_shift);
    //window->statusBar()
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
