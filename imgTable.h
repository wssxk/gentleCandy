#ifndef IMGTABLE_H
#define IMGTABLE_H

#include <QWidget>
#include <QGridLayout>
#include <QSize>
#include <QList>

#include "imgCell.h"
#include "imgHandle.h"
#include "imgViewer.h"
//#include "cellScroll.h"

class imgTable : public QWidget
{
    Q_OBJECT
private:
    //int isInit;
    int cellNum;
    imgCell img[50];
    QGridLayout qgl;
    QSize currentSize;
    imgViewer* iv;


public:
    imgTable(int cn = 50, QList<imgHandle>* page = NULL, QWidget *parent = NULL);


protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:
    void sendCellRelease(imgHandle* handle);

public slots:
    void getGetSingle(imgHandle* hd);
};

#endif // IMGTABLE_H
