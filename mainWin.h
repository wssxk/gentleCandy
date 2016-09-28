#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QTableWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QStringList>
#include <QString>
#include <QList>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

//#include <QHBoxLayout>

#include "cellScroll.h"
#include "imgHandle.h"

class mainWin : public QWidget
{
    Q_OBJECT
private:
    cellScroll* cs;
    QWidget* info;
    //QHBoxLayout qhl;
    QGridLayout* qgl;
    QStringList allSoures;
    QString currentSource;
    imgHandle* currentMainPage;


    QComboBox* sourceSwitch;
    QPushButton* sourceChecked;

    int pageNum;
    QPushButton* previousPage;
    QPushButton* nextPage;
    QLabel* pageInfo;
    QHBoxLayout* pageLayout;
public:
    mainWin(QWidget *parent = 0);

    //QTableWidget qtw;
    //QScrollArea qsa;
    //QGridLayout qgl;
    //imgCell* ic[10];

signals:

public slots:
    void mainPageGetted(QList<imgHandle>*);
    void getPreviousPage();
    void getNextPage();
    void switchSource();
};

#endif // MAINWIN_H
