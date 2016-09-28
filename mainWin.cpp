#include <QDir>
#include <iostream>

#include "mainWin.h"

mainWin::mainWin(QWidget *parent) : QWidget(parent)
{
    //ic[0] = new imgCell;
    //qgl.addWidget(&qtw, 1, 1);
    //qtw.setCellWidget(1,1,ic[0]);
    //qsa.setWidget(ic[0]);
    //qsa.setWidgietResizable(true);
    //qgl.addWidget(&qsa);
    //this->setLayout(&qgl);


    sourceSwitch = new QComboBox;
    sourceChecked = new QPushButton("change");
    QObject::connect(sourceChecked, SIGNAL(clicked()), this, SLOT(switchSource()));



    pageNum = 1;

    //char str[3];
    //sprintf(str, "%d", pageNum);
    previousPage = new QPushButton("<<&Previous");
    previousPage->setEnabled(false);
    nextPage = new QPushButton("&Next>>");
    pageInfo = new QLabel();
    pageInfo->setNum(pageNum);
    pageLayout = new QHBoxLayout;

    QObject::connect(previousPage, SIGNAL(clicked()), this, SLOT(getPreviousPage()));
    QObject::connect(nextPage, SIGNAL(clicked()), this, SLOT(getNextPage()));


    currentMainPage = new imgHandle;

    QDir dir("./modules");  //确定当前目录
    allSoures = dir.entryList();    //获取当线目录下文件/目录名列表
    allSoures.removeAt(0);  //删除.和..
    allSoures.removeAt(0);

    sourceSwitch->addItems(allSoures);

    QObject::connect(currentMainPage, SIGNAL(mainPageGetted(QList<imgHandle>*)), this, SLOT(mainPageGetted(QList<imgHandle>*)));

    currentSource = allSoures.at(0);    //获取当前模块名

    this->setWindowTitle(QString("GentleCandy-") + currentSource );

    std::cout << "current: " << currentSource.toAscii().data() << std::endl;

    std::cout << "allSource: " << std::endl;
    for(int t = 0; t < allSoures.size(); t ++)
    {
        std::cout << allSoures.at(t).toAscii().data() << std::endl;
    }

    //设置当前页面
    currentMainPage->setMainPage(currentSource, pageNum);
    //currentMainPage->setMainPage("safebooru", pageNum);
    //爬取页面信息
    //QList<imgHandle>* currentMainPageImg = currentMainPage->getMainPage();

    currentMainPage->start();

    //cs = new cellScroll(currentMainPageImg);
    cs = new cellScroll;
    info = new QWidget;
    qgl = new QGridLayout;
    qgl->setSpacing(0);



    info->setFixedHeight(50);
    pageLayout->addWidget(sourceSwitch);
    pageLayout->addWidget(sourceChecked);
    pageLayout->insertStretch(3);
    pageLayout->addWidget(previousPage);
    pageLayout->addWidget(pageInfo);
    pageLayout->addWidget(nextPage);

    info->setLayout(pageLayout);



    qgl->addWidget(info, 1, 1);
    qgl->addWidget(cs, 2, 1);
    this->setLayout(qgl);
    this->setMinimumSize(1300, 800);
    //this->resize(1300, 800);

}


void mainWin::mainPageGetted(QList<imgHandle> * result)
{
    delete cs;
    cs = new cellScroll(result);
    qgl->addWidget(cs, 2, 1);

}


void mainWin::getPreviousPage()
{
    if(pageNum <= 1)
    {
        previousPage->setEnabled(false);
        return;

    }

    pageNum --;

    delete cs;
    cs = new cellScroll;
    qgl->addWidget(cs, 2, 1);

    char str[3];
    sprintf(str, "%d", pageNum);
    pageInfo->setText(str);


    currentMainPage->exit();
    currentMainPage->setMainPage(currentSource, pageNum);
    currentMainPage->start();

}

void mainWin::getNextPage()
{
    pageNum ++;

    if(pageNum > 1)
    {
        previousPage->setEnabled(true);
    }


    delete cs;
    cs = new cellScroll;
    qgl->addWidget(cs, 2, 1);

    char str[3];
    sprintf(str, "%d", pageNum);
    pageInfo->setText(str);

    currentMainPage->exit();
    currentMainPage->setMainPage(currentSource, pageNum);
    currentMainPage->start();

}


void mainWin::switchSource()
{
    currentSource = sourceSwitch->currentText();
    this->setWindowTitle(QString("GentleCandy-") + currentSource );
    pageNum = 1;
    pageInfo->setNum(pageNum);

    delete cs;
    cs = new cellScroll;
    qgl->addWidget(cs, 2, 1);

    currentMainPage->exit();
    currentMainPage->setMainPage(currentSource, pageNum);
    currentMainPage->start();


}
