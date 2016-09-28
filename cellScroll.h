#ifndef CELLSCROLL_H
#define CELLSCROLL_H

#include <QScrollArea>
#include <QResizeEvent>
#include <QList>

#include "imgTable.h"
#include "imgHandle.h"


class cellScroll : public QScrollArea
{
    Q_OBJECT
private:
    imgTable* it;
    cellScroll* cellShow;

public:
    cellScroll(QList<imgHandle>* page = NULL, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

public slots:
    void getCellRelease(imgHandle* handle);
    void getCatalogGetted(QList<imgHandle>* result);
};

#endif // CELLSCROLL_H
