/*
 * 用来管理图片的类
 */


#ifndef IMGHANDLE_H
#define IMGHANDLE_H

#include <QObject>
#include <QString>
#include <QList>
#include <QThread>
#include <QWidget>

class imgHandle:public QThread
{
    Q_OBJECT
private:
    int state;  //状态:1.主页面，2.分类，3.单图
    QString sign;   //模块或者图片的名字
    int pageNum;    //页数
    QString showImg;    //展示的图片
    QString site;   //分类里的图片，或者单图的链接
    QString modules;
public:
    imgHandle(int st = -1,
              QString sg = QObject::tr(""),
              int pn = -1,
              QString si = QObject::tr(""),
              QString sit = QObject::tr(""),
              QString md = QObject::tr("")
              //QObject* parent = NULL
              );
    imgHandle(const imgHandle&);
    imgHandle& operator =(const imgHandle&);

    //获取类的各项数据
    int getState();
    QString getSign();
    int getPage();
    QString getShowImg();
    QString getSite();

    //定义类的类型
    void setMainPage(QString moduleName, int page);
    void setCatalog(QString catalogName, QString show, QString catalogSite);
    void setSingleImg(QString imgName, QString show, QString imgSite);


    //根据类型爬取信息
    QList<imgHandle>* getMainPage();
    QList<imgHandle>* getCatalog();

protected:
    void run();

signals:
    void mainPageGetted(QList<imgHandle>*);
    void catalogGetted(QList<imgHandle>*);


};

#endif // IMGHANDLE_H
