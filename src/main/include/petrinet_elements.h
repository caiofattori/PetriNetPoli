#ifndef PETRINET_ELEMENTS_H
#define PETRINET_ELEMENTS_H

#include <QtWidgets/QGraphicsEllipseItem>
#include <QtCore/QRectF>
#include <QtGui/QBrush>

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

class PNBasicPlace : public QGraphicsEllipseItem
{

public:
    explicit PNBasicPlace(int, int);
    virtual ~PNBasicPlace();
    virtual void paint(QPainter *, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    //virtual QRectF boundingRect();

private:
    QRectF item_draw;
    QBrush item_brush;
};

#endif // PETRINET_ELEMENTS_H
