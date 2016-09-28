#include "cellScroll.h"

cellScroll::cellScroll(QList<imgHandle>* page, QWidget *parent)
{
    if(page != NULL)
    {
        it = new imgTable(page->size(), page);
    }
    else
    {
        it = new imgTable;
    }
    //this->setWidgetResizable(true);

    QObject::connect(it, SIGNAL(sendCellRelease(imgHandle*)), this, SLOT(getCellRelease(imgHandle*)));

    this->setWidget(it);
    this->resize(800, 800);
}

void cellScroll::paintEvent(QPaintEvent *event)
{
    it->repaint(this->rect());
}

void cellScroll::resizeEvent(QResizeEvent *event)
{
    it->resize(this->size().width() - 20, 800);
    //it->repaint();
    //this->repaint();
}


void cellScroll::getCellRelease(imgHandle *handle)
{
    cellShow = new cellScroll;
    cellShow->setWindowModality(Qt::ApplicationModal);
    cellShow->show();
    QObject::connect(handle, SIGNAL(catalogGetted(QList<imgHandle>*)), this, SLOT(getCatalogGetted(QList<imgHandle>*)));
    handle->start();

}


void cellScroll::getCatalogGetted(QList<imgHandle> *result)
{
    cellShow->close();
    delete cellShow;
    cellShow = new cellScroll(result);
    cellShow->setWindowModality(Qt::ApplicationModal);
    cellShow->show();

}
