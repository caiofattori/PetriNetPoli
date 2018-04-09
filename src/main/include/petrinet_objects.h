#ifndef PETRINET_OBJECTS_H
#define PETRINET_OBJECTS_H

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtGui/QPen>
#include <QtGui/QMouseEvent>

class QPainter;
class QRectF;
class QPointF;
class QObject;
class PetriNetStMach;
class QPushButton;

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

class PNGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit PNGraphicsView(PNGraphicsScene *, QWidget *);
    int x_clicked;
    int y_clicked;
    PetriNetStMach *my_mach;
    QPushButton *btn_place;

public slots:
    void mousePressEvent(QMouseEvent *);

signals:
    void mouseLeftClick();
};

#endif // PETRINET_OBJECTS_H
