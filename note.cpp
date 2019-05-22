#include "note.h"

Note::Note()
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
    mouseIsPressed=false;
}


QRectF Note::boundingRect()const{
    return QRect(0,0,80,80);
}
void Note::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(widget);
//    painter->drawRect(QRect(0,0,50,20));
    QPointF *points = new QPointF[3];
    points[0] = QPointF(0,-80);
    points[1] = QPointF(0,80);
    points[2] = QPointF(80,0);
    painter->drawPolygon(points,3);
}


QPainterPath Note::shape()const{
    QPainterPath path;
//    path.addRect(0, 0, 50, 20);
    path.moveTo(0, -80.0);
    path.lineTo(0.0, 80.0);
    path.lineTo(80.0, 0.0);
//    path.lineTo(75.0, -30.0);
    path.closeSubpath();
    return path;
}
void Note::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug("Item clicked");
    mouseIsPressed = true;
    //    x = event->scenePos().x();
    //    y = event->scenePos().y();
        QGraphicsItem::mousePressEvent(event);
        update();
}
void Note::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    qDebug("Item moved");
//    if(mouseIsPressed){
//        float x = event->scenePos().x();
//        float y = event->scenePos().y();
//        this->setX(x);
//        this->setY(y);
//    }
    QGraphicsItem::mouseMoveEvent(event);
        update();
}
void Note::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    qDebug("Item released");
    //    x = event->scenePos().x();
    //    y = event->scenePos().y();
    mouseIsPressed=false;
        QGraphicsItem::mouseReleaseEvent(event);
        update();
}
