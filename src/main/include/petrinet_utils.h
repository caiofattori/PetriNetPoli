#ifndef PETRINET_UTILS_H
#define PETRINET_UTILS_H

#include<QtCore/QStateMachine>

class QState;
class PetriNetWindow;
class PetriNetStateInserting;
class PetriNetStateIdle;
class PetriNetEditableNet;

class PetriNetStMach : public QStateMachine
{
    Q_OBJECT

public:
    explicit PetriNetStMach(PetriNetWindow *, PetriNetEditableNet *);
    enum Mstate{ IDLE=1, INSERTING=2 };
    PetriNetStateIdle *idle;
    PetriNetStateInserting *inserting;
    PetriNetStateIdle *idle_shift;
    PetriNetStateInserting *inserting_shift;
    PetriNetWindow *window;
    PetriNetEditableNet *view;
    enum Mstate currentState;
    void setState(Mstate);
    PetriNetStMach::Mstate getState();

private:
    void createShiftTransition(QState *, QState *);
};

class PetriNetStateInserting : public QState
{
    Q_OBJECT

public:
    explicit PetriNetStateInserting();

protected:
    virtual void onEntry(QEvent *event);
    virtual void onExit(QEvent *event);
};

class PetriNetStateIdle : public QState
{
    Q_OBJECT

public:
    explicit PetriNetStateIdle();

protected:
    virtual void onEntry(QEvent *event);
    virtual void onExit(QEvent *event);
};

#endif // PETRINET_UTILS_H
