
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMessageBox>
#include <QtCore/QPointF>
#include <QtCore/QRectF>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <cmath>
#include<iostream>
#include "petrinet.h"
#include "petrinet_objects.h"
#include "petrinet_utils.h"

PNGraphicsScene::PNGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    :QGraphicsScene(x, y, width, height, parent)
{
    //pen_back = QPen()
    int w = width/20 - 1;
    int h = height/20 - 1;
    size_points = w*h;
    points = new QPointF[size_points];
    for(int i=0; i < w; i++){
        for(int j=0; j < h; j++){
          points[i*h + j] = QPointF(i*20 + 10, j*20 + 10);
        }
    }
}

void PNGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect){
    painter->setPen(Qt::SolidLine);
    painter->drawPoints(points, size_points);
}

PNGraphicsScene::~PNGraphicsScene()
{
    delete[] points;

}

PNGraphicsView::PNGraphicsView(PNGraphicsScene *gs, QWidget *parent)
    :QGraphicsView(gs, parent)
{
    this->x_clicked = -1;
    this->y_clicked = -1;
}

void PNGraphicsView::mousePressEvent(QMouseEvent *e)
{
    QMessageBox m;
    m.setText("Bla");
    m.exec();
    QPointF pt = mapToScene(e->pos());
    double aux = fmod(pt.x(),20.0);
    if(aux > 10){
        this->x_clicked = pt.x() + (20 - aux);
    }
    else{
        this->x_clicked = pt.x() - aux;
    }
    aux = fmod(pt.y(),20.0);
    if(aux > 10){
        this->y_clicked = pt.y() + (20 - aux);
    }
    else{
        this->y_clicked = pt.y() - aux;
    }
}
