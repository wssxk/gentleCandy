#ifndef IMGCELL_H
#define IMGCELL_H

#include <QWidget>
#include <QPalette>
#include <QSize>
#include <QImage>
#include <QPixmap>
#include <QLabel>

#include "imgHandle.h"
#include "imgDownloader.h"


//#include "cellScroll.h"

class imgCell : public QLabel
{
    Q_OBJECT

private:
    QSize s;
    QPixmap* img;
    imgDownloader* downloader;
    imgHandle* handle;
public:
    imgCell(QWidget *parent = 0);
    //QPalette qplt;
    //void switchImg();
    void setImgHandle(imgHandle ih);

protected:
    void resizeEvent(QResizeEvent* event);
    //void paintEvent(QPaintEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

signals:
    void sendRelease(imgHandle* hd);
    void sendGetSingle(imgHandle* hd);

public slots:
    void downloadFinished();

};

#endif // IMGCELL_H
