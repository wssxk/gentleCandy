#-------------------------------------------------
#
# Project created by QtCreator 2016-09-18T08:46:45
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gentleCandy-label
TEMPLATE = app


LIBS += -L/usr/lib64/python3.5/config-3.5m/ -lpython3.5m


SOURCES += main.cpp \
    cellScroll.cpp \
    imgCell.cpp \
    imgTable.cpp \
    mainWin.cpp \
    imgHandle.cpp \
    imgDownloader.cpp \
    crawler.cpp \
    imgViewer.cpp

HEADERS  += \
    cellScroll.h \
    imgCell.h \
    imgTable.h \
    mainWin.h \
    imgHandle.h \
    imgDownloader.h \
    crawler.h \
    imgViewer.h

RESOURCES += \
    img.qrc

FORMS += \
    form.ui

DISTFILES += \
    test.jpg
