#include <iostream>
#include "imgTable.h"
//#include "imgViewer.h"

imgTable::imgTable(int cn, QList<imgHandle>* page, QWidget *parent) : QWidget(parent)
{
    //this->hide();
    cellNum = cn;
    currentSize.setHeight(1);
    currentSize.setWidth(1);
    iv = NULL;
    //isInit = 1;

    for(int i = 0; i < cellNum; i ++)
    {
        if(page != NULL)
        {
            img[i].setImgHandle(page->at(i));
            QObject::connect(&img[i], SIGNAL(sendRelease(imgHandle*)), this, SIGNAL(sendCellRelease(imgHandle*)));
            QObject::connect(&img[i], SIGNAL(sendGetSingle(imgHandle*)), this, SLOT(getGetSingle(imgHandle*)));
        }
        qgl.addWidget(&img[i], int(i / 5) + 1, int(i % 5) + 1);
        //std::cout << "t" << std::endl;
    }

    //qgl.addWidget(&img[0], 1, 1);
    //qgl.addWidget(&img[1], 1, 2);
    //img[0].switchImg();
    qgl.setSpacing(10);

    this->setLayout(&qgl);

    //this->resize(800, 800);
    //currentSize.setHeight(img[0].height() * 4 + 5 * 3);

    //this->resize(600, img[0].height() * 4 + 5 * 3);
    //this->hide();
    this->setMinimumWidth(600);

    //this->repaint();
    this->resize(800, 600);
    //this->show();
    //this->resize(800,600);
    //this->resizeEvent(NULL);
    //this->setFixedHeight(img[0].height() * 4 + 10 * 5);
    //this->setFixedHeight(img[0].height() * 4 + 5 * 3);
    //this->setMinimumHeight(600);
    //this->resize(this->sizeHint());
    //currentSize = this->size();
    //isInit == 0;
    //this->resize(800, 600);
    //this->show();

}


void imgTable::paintEvent(QPaintEvent *event)
{
    //qgl.setGeometry(img[0].rect());
    //QWidget::paintEvent(event);
//    if(this->size() == currentSize)
//        return;

    //currentSize
    //this->setFixedHeight(img[0].height() * 4 + 10 * 5);
    //currentSize = this->size();

    if(this->size() == currentSize){
        //std::cout << "t" << std::endl;
        return;
    }

    int rowNum = (cellNum - 1) / 5 + 1;
    currentSize.setWidth(this->width());
    currentSize.setHeight(img[0].height() * rowNum + 10 * (rowNum + 1));

    for(int i = 0; i < cellNum; i ++)
        img[i].update();


    this->setFixedHeight(img[0].height() * rowNum + 10 * (rowNum + 1));

//    for(int i = 0; i < cellNum; i ++)
//        img[i].repaint();

}


void imgTable::resizeEvent(QResizeEvent *event)
{
    /*
    if(this->size() == currentSize){
        //std::cout << "t" << std::endl;
        return;
    }

    int rowNum = (cellNum - 1) / 5 + 1;
    currentSize.setWidth(this->width());
    currentSize.setHeight(img[0].height() * rowNum + 10 * (rowNum + 1));
    this->setFixedHeight(img[0].height() * rowNum + 10 * (rowNum + 1));

    */

    this->update();
}


void imgTable::getGetSingle(imgHandle *hd)
{
    if(iv != NULL)
        delete iv;
    iv = new imgViewer(hd);
    iv->setWindowModality(Qt::ApplicationModal);
    iv->show();

}
