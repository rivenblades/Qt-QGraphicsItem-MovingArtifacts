#ifndef __SCENE_H__
#define __SCENE_H__

#include <QRectF>
#include <QGraphicsScene>

#include <note.h>
class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject *parent);

protected:
    virtual void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
    QColor _color_background;
    QColor _color_light;
    QColor _color_dark;

    QPen _pen_light;
    QPen _pen_dark;

    QBrush _brush_background;


    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif
