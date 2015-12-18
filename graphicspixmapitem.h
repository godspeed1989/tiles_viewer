#ifndef GRAPHICSPIXMAPITEM_H
#define GRAPHICSPIXMAPITEM_H

#include <QPixmap>
#include <QGraphicsPixmapItem>

static const int imgsize = 256;

class GraphicsPixmapItem : public QGraphicsPixmapItem
{
public:
    explicit GraphicsPixmapItem(int r, int c, const QString& p);
    void load();
private:
    int row, col;
    QString path;
    bool loaded;
};

#endif // GRAPHICSPIXMAPITEM_H
