#include "graphicspixmapitem.h"
#include <QDebug>

GraphicsPixmapItem::GraphicsPixmapItem(int r, int c, const QString& p)
{
    row = r;
    col = c;
    path = p;
    loaded = false;

    QPixmap null_pixmap;
    null_pixmap.load("../tiles_viewer/maps/null.png");
    this->setPixmap(null_pixmap);
    this->setPos(col*imgsize, row*imgsize);
}

void GraphicsPixmapItem::load()
{
    if (loaded)
        return;

    QPixmap pixmap;
    if (false == pixmap.load(path))
    {
        qDebug() << "load error:" << path;
        return;
    }
    pixmap.scaled(imgsize, imgsize);
    this->setPixmap(pixmap);
    this->setPos(col*imgsize, row*imgsize);
    loaded = true;
}
