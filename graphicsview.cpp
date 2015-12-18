#include "graphicsview.h"
#include "graphicspixmapitem.h"
#include <QDebug>

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0)
        scale(1.05, 1.05);
    else
        scale(0.95, 0.95);
    event->accept();
}

void GraphicsView::paintEvent(QPaintEvent *event)
{
    QList<QGraphicsItem*> itemlist = items(0, 0, width(), height());
    foreach (QGraphicsItem* item, itemlist)
    {
        item->data(0);
        GraphicsPixmapItem *pitem = dynamic_cast<GraphicsPixmapItem*>(item);
        pitem->load();
    }
    QGraphicsView::paintEvent(event);
}
