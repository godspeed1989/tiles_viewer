#ifndef MAPVIEWER_H
#define MAPVIEWER_H

#include <QWidget>
#include <QGraphicsScene>
#include "graphicsview.h"
#include "graphicspixmapitem.h"

class MapViewer : public QWidget
{
    Q_OBJECT
public:
    MapViewer(QWidget *parent = 0);
    ~MapViewer();
private:
    QGraphicsScene *map_scene;
    GraphicsView *map_view;
    void load_map(const int zoomlevel,
                  const QString &base,
                  const QString &suffix);
private slots:
    void zoomSliderValueChanged(int zoom);
};

#endif // MAPVIEWER_H
