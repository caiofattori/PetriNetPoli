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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QPushButton>
#include <QIcon>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QStatusBar>
#include <iostream>
#include <string>
#include "petrinet.h"
#include "petrinet_utils.h"


PetriNetWindow::PetriNetWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* wg = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    wg->setLayout(layout);
    tbox = new QToolBox;
    tbox->setMaximumWidth(150);
    createPNBasicToolBox();

    twid = new QTabWidget;
    createEditPanel();

    tbar = new QToolBar;
    createBasicToolBar();

    //QGroupBox *gbox = new QGroupBox;
    layout->addWidget(tbox);
    layout->addWidget(twid);
    addToolBar(tbar);
    //layout->addWidget(gbox);
    setCentralWidget(wg);
    setWindowTitle("Petri Net Poli");
    count_net = 0;
    statusBar()->showMessage("Começando");
}

void PetriNetWindow::createPNBasicToolBox()
{
    QWidget *t0 = new QWidget;
    QGridLayout *lay_t0 = new QGridLayout;
    QIcon icon_place("./src/main/resource/place_icon.svg");
    btn_place = new QPushButton(icon_place, "", this);
    QIcon icon_transition("./src/main/resource/transition_icon.svg");
    QPushButton *btn_transition = new QPushButton(icon_transition, "", this);
    QIcon icon_arc("./src/main/resource/arc_icon.svg");
    QPushButton *btn_arc = new QPushButton(icon_arc, "", this);
    t0->setLayout(lay_t0);
    lay_t0->addWidget(btn_place,0,0,Qt::AlignLeft | Qt::AlignTop);
    lay_t0->addWidget(btn_transition,0,1,Qt::AlignLeft | Qt::AlignTop);
    lay_t0->addWidget(btn_arc,0,2,Qt::AlignLeft | Qt::AlignTop);
    tbox->addItem(t0, "PN elements");
}

void PetriNetWindow::createGraphicToolBox()
{
    QWidget *t1 = new QWidget;
    tbox->addItem(t1, "Graphics");
}

void PetriNetWindow::createEditPanel()
{

}

void PetriNetWindow::createBasicToolBar()
{
    const QIcon icon_new = QIcon::fromTheme("document-new", QIcon("./src/main/resource/new_icon.svg"));
    QAction *act_new = new QAction(icon_new, tr("&New..."), this);
    act_new->setStatusTip(tr("Create a new PNML file"));
    connect(act_new, &QAction::triggered, this, &PetriNetWindow::addNewNet);
    tbar->addAction(act_new);
}

void PetriNetWindow::addNewNet()
{
    if(twid->count() == 0){
        btn_place->setCheckable(true);
    }
    else{
        btn_place->setChecked(false);
    }

    PetriNetEditableNet *new_net = new PetriNetEditableNet(this);
    twid->addTab(new_net, "new_pnml" + QString::number(count_net));
    twid->setCurrentWidget(new_net);
    count_net ++;
}

void PetriNetWindow::addNewBasicPlace()
{
    if(twid->count() > 0){
        ((PetriNetEditableNet *)twid->currentWidget())->addNewBasicPlace();
    }
}
