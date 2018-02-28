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

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QGroupBox>
#include "petrinet.h"


PetriNetWindow::PetriNetWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* wg = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    wg->setLayout(layout);
    QToolBox *tbox = new QToolBox;
    QWidget *t0 = new QWidget;
    QWidget *t1 = new QWidget;
    tbox->addItem(t0, "tools0");
    tbox->addItem(t1, "tools1");
    QTabWidget *twid = new QTabWidget;
    QWidget *p0 = new QWidget;
    QWidget *p1 = new QWidget;
    twid->addTab(p0, "tab1");
    twid->addTab(p1, "tab2");
    QGroupBox *gbox = new QGroupBox;
    layout->addWidget(tbox);
    layout->addWidget(twid);
    layout->addWidget(gbox);
    setCentralWidget(wg);
    setWindowTitle("VAMOS COMEÇAR");
}


