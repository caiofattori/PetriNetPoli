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
#include <QtWidgets/QVBoxLayout>
#include <QFile>
#include <QFormBuilder>

#include "petrinet.h"


PetriNetWindow::PetriNetWindow()
{
    QFormBuilder loader;
    QFile form(":/src/main/resource/petrinetwindow.ui");
    form.open(QFile::ReadOnly);
    QWidget* wg = loader.load(&form, this);
    form.close();
}


