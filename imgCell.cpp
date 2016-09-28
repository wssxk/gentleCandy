#include <QPalette>
#include <iostream>
#include <QImage>
#include <QPainter>
#include "imgCell.h"
#include "cellScroll.h"
#include "crawler.h"

imgCell::imgCell(QWidget *parent) : QLabel(parent)
{
    //QPalette qplt;
    //qplt.setColor(QPalette::Background, QColor(167, 167, 167));
    //img = new QPixmap("/home/wssxk/tmp/test2.jpg");
    //*img = img->scaled(QSize(160 * 3, 90 * 3), Qt::KeepAspectRatioByExpanding);
    //*img = img->copy(0, 0, 160 * 3, 90 * 3);
    //std::cout << img->size().width() << " X " << img->size().height() << std::endl;
    //this->setAutoFillBackground(true);
    //this->setPalette(qplt);
    //this->setMinimumWidth(500);
    //int unit = this->sizeHint().width() / 2.0;
    handle = NULL;
    downloader = new imgDownloader;
    QObject::connect(downloader, SIGNAL(finished()), this, SLOT(downloadFinished()));
    img = new QPixmap(":/refreshing.jpg");
    s.setWidth(1);
    s.setHeight(1);
    this->setPixmap(*img);
    this->setScaledContents(true);
    //this->resize(160 * 3, 90 * 3);
    //this->setFixedSize(s);
    //s = this->size();
}



void imgCell::resizeEvent(QResizeEvent *event)
{

    /*
    if(s == this->size())
    {
        std::cout << "yy" << std::endl;
        return;
    }
    std::cout << this->size().width() << " X " << this->size().height() << std::endl;
    QSize tmpSize(this->size().width(), this->size().height() / 2);
    s = tmpSize;
    this->resize(s);
    //s = this->size();
    std::cout << "ttt" << std::endl;

    this->repaint();
    QWidget::resizeEvent(event);
    */

    if(s == this->size())
    {
        return;
    }

    s.setWidth(this->width());
    s.setHeight(this->width() * (9/16.0));

    this->setFixedHeight(this->width() * (9/16.0));

}

/*

void imgCell::paintEvent(QPaintEvent *event)
{

    if(s != this->size())
    {
        s.setWidth(this->size().width());
        s.setHeight((this->size().height()) / 2.0);
        this->resize(s);
    }


    if(s == this->size())
    {
        return;
    }

    //this->resize(this->width(), 0.5 * this->width());
    s.setWidth(this->width());
    s.setHeight(this->width() * (9/16.0));

    //QPainter painter1(this);
    //painter1.drawPixmap(QRect(0, 0, s.width(), s.height()), *img);

    //this->setPixmap(*img);
    this->setFixedHeight(this->width() * (9/16.0));
    //QWidget::paintEvent(event);

}


*/

/*
void imgCell::switchImg()
{

    delete img;
    img = new QPixmap("/home/wssxk/tmp/test1.jpg");
    *img = img->scaled(QSize(160 * 3, 90 * 3), Qt::KeepAspectRatioByExpanding);
    *img = img->copy(0, 0, 160 * 3, 90 * 3);
    this->setPixmap(*img);
}
*/

//***设置页面，这里应通过多线程启动下载程序下载图片并更新
void imgCell::setImgHandle(imgHandle ih)
{
    handle = new imgHandle(ih);
    QString url = ih.getShowImg();
    downloader->setUrl(url);
    downloader->startDownload();
    //delete img;
    //img = new QPixmap(url);
    //*img = img->scaled(QSize(160 * 3, 90 * 3), Qt::KeepAspectRatioByExpanding);
    //*img = img->copy(0, 0, 160 * 3, 90 * 3);
    //this->setPixmap(*img);
}

void imgCell::downloadFinished()
{
    std::cout << "finished" << std::endl;
    img->loadFromData(downloader->getData());
    *img = img->scaled(QSize(160 * 3, 90 * 3), Qt::KeepAspectRatioByExpanding);
    *img = img->copy(0, 0, 160 * 3, 90 * 3);
    this->setPixmap(*img);
}


void imgCell::mouseReleaseEvent(QMouseEvent *event)
{
    if(handle == NULL)
        return;
    if(handle->getState() == 3)
    {
        emit sendGetSingle(handle);
        return;
    }


    //std::cout << "YYYYYYYYYYY" << std::endl;
    //cellScroll* cs = new cellScroll;
    //cs->resize(1200, 800);
    //cs->setWindowModality(Qt::ApplicationModal);
    //cs->show();
    emit sendRelease(handle);


}

