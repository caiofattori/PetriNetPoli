#ifndef PETRINET_UTILS_H
#define PETRINET_UTILS_H

#include<QtCore/QStateMachine>

class QState;
class PetriNetWindow;

class PetriNetStMach : public QStateMachine
{
    Q_OBJECT

public:
    explicit PetriNetStMach(PetriNetWindow *);
    QState *idle;
    QState *inserting;
    PetriNetWindow *window;

private:
    void createShiftTransition(QState *, QState *);
};

#endif // PETRINET_UTILS_H
