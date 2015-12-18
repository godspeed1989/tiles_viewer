QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tiles_viewer
TEMPLATE = app

SOURCES += main.cpp \
           mapviewer.cpp \
           graphicsview.cpp \
           graphicspixmapitem.cpp

HEADERS  += mapviewer.h \
            graphicsview.h \
            graphicspixmapitem.h
