/**
*
*   PetriNetPoli is a GUI for modeling, analysing and simulating Petri net
*   Copyright (C) 2017  Caio C Fattori
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*/

#ifndef PETRINET_H
#define PETRINET_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
class QToolBox;
class QTabWidget;
class QToolBar;
class QPushButton;
class PetriNetStMach;
class PNGraphicsScene;
class PNGraphicsView;

class PetriNetWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit PetriNetWindow(QWidget *parent = nullptr);
    QPushButton *btn_place;

private:
    void createPNBasicToolBox ();
    void createGraphicToolBox ();
    void createEditPanel ();
    void createBasicToolBar();
    void addNewNet();
    void addNewBasicPlace();
    QToolBox *tbox;
    QTabWidget *twid;
    QToolBar *tbar;
    int count_net;
};

class PetriNetEditableNet : public QWidget
{
    Q_OBJECT

public:
    explicit PetriNetEditableNet(PetriNetWindow *);
    void addNewBasicPlace();
    PNGraphicsScene *gs;
    PNGraphicsView *gv;
    PetriNetStMach *stmach;
    PetriNetWindow *win;

protected:
    void showEvent(QShowEvent *);
};

#endif
