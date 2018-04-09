
#include "petrinet.h"
#include "petrinet_objects.h"
#include "petrinet_elements.h"
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsEllipseItem>
#include <QtGui/QPainter>
#include <QtWidgets/QStyleOptionGraphicsItem>
#include <QtWidgets/QWidget>
#include <QtGui/QBrush>

PNBasicPlace::PNBasicPlace(int x, int y)
    : QGraphicsEllipseItem(x, y, 20, 20)
{
    item_draw = QRectF(x, y, 20, 20);
    item_brush = QBrush(Qt::white, Qt::SolidPattern);
}

PNBasicPlace::~PNBasicPlace(){}

void PNBasicPlace::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(item_brush);
    painter->drawEllipse(item_draw);
}

/*QRectF PNBasicPlace::boundingRect(){
    return QRectF(0,0,10,10);
}*/
