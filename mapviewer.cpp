#include "mapviewer.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QDebug>
#include <cmath>

MapViewer::MapViewer(QWidget *parent)
    : QWidget(parent)
{
    this->map_scene = new QGraphicsScene(this);
    this->map_view = new GraphicsView(map_scene, this);
    QSlider *zoomSlider = new QSlider(Qt::Vertical, this);
    zoomSlider->setRange(0, 6);
    zoomSlider->setValue(0);
    zoomSlider->setTickPosition(QSlider::TicksRight);
    connect(zoomSlider, SIGNAL(valueChanged(int)),
            SLOT(zoomSliderValueChanged(int)));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(map_view);
    layout->addWidget(zoomSlider);

    //load_map(6, "/home/yl/work/tiles_viewer/satellite", "");
    //load_map(4, "/home/yl/.MapGraphicsCache/MapQuest Aerial Tiles", ".jpg");
    //load_map(3, "/home/yl/.MapGraphicsCache/MapQuestOSM Tiles", ".png");
    load_map(0, "../tiles_viewer/maps", ".png");
}

void MapViewer::zoomSliderValueChanged(int zoom)
{
    load_map(zoom, "../tiles_viewer/maps", ".png");
}

void MapViewer::load_map(const int zoomlevel,
                         const QString &base,
                         const QString &suffix)
{
    int col, row, size = (int)std::pow(2, zoomlevel);

    qDebug() << size;
    map_scene->clear();

    QString path = base+"/"+QString::number(zoomlevel)+"/%1/%2"+suffix;
    for (col = 0; col < size; col++)
    {
        for (row = 0; row < size; row++)
        {
            int dir = col, file = row;
            GraphicsPixmapItem *pixmap_item =
                    new GraphicsPixmapItem(row, col, path.arg(dir).arg(file));
            map_scene->addItem(pixmap_item);
        }
    }

    map_scene->setSceneRect(0, 0, imgsize*size, imgsize*size);
}

MapViewer::~MapViewer()
{

}
