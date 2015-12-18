#ifndef GRAPHICVIEW_H
#define GRAPHICVIEW_H

#include <QWheelEvent>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QGraphicsScene *scene, QWidget *parent = 0)
        : QGraphicsView(parent)
    {
        setScene(scene);
        setDragMode(QGraphicsView::ScrollHandDrag);
        setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    }
protected:
    void wheelEvent(QWheelEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // GRAPHICVIEW_H
