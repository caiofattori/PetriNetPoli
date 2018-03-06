#ifndef PETRINET_OBJECTS_H
#define PETRINET_OBJECTS_H

#include <QtWidgets/QGraphicsScene>
#include <QtGui/QPen>

class QPainter;
class QRectF;
class QPointF;
class QObject;

class PNGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit PNGraphicsScene(qreal, qreal, qreal, qreal, QObject *);
    virtual ~PNGraphicsScene();

private:
    void drawBackground(QPainter *, const QRectF &);

    QPointF *points;
    int size_points;

    QPen pen_back;
};

#endif // PETRINET_OBJECTS_H
