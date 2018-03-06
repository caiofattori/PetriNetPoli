
#include <QtWidgets/QGraphicsScene>
#include <QtCore/QPointF>
#include <QtCore/QRectF>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include "petrinet.h"
#include "petrinet_objects.h"

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
