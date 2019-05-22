#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMoveEvent>
#include <QStyleOptionGraphicsItem>
#include <QPainterPath>
#include <QRectF>

class Note : public QGraphicsItem
{
    friend class Scene;
public:
    Note();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
        QPainterPath shape() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    bool mouseIsPressed;
};

#endif // NOTE_H
