/*
 * 用来展示图片的窗口
 */


#ifndef IMGVIEWER_H
#define IMGVIEWER_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QByteArray>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QSize>
#include <QFile>
#include <QDir>

#include "imgHandle.h"
#include "imgDownloader.h"


class imgViewer : public QWidget
{
    Q_OBJECT
private:
    QScrollArea* qsa;   //用于滚动的窗口
    QLabel* imgLabel;   //显示图片的标签
    QPixmap* img;   //图片
    QGridLayout* qgl;   //布局
    QByteArray* imgBuff;    //图片的缓存区

    QSlider* imgTweak;  //调整图片大小的控件
    QHBoxLayout* qhbl;  //布局
    QPushButton* imgSave;   //保存图片的按钮

    imgHandle* handle;  //图片信息
    imgDownloader* downloader;  //下载图片的类

    QLabel* showProgress;

    //QSize* imgSize;

    int isFinished;     //图片是否已下载标记

public:
    //构造函数
    imgViewer(imgHandle* hd = NULL);
    ~imgViewer();

public slots:
    //下载进度
    void downloadProgress(qint64 bytesRec, qint64 bytesTol);
    //下载已完成
    void finished();
    //下载发生错误
    void error(QNetworkReply::NetworkError code);
    //调整图片大小
    void tweakValueChanged(int v);
    //保存图片
    void saveImg();
};

#endif // IMGVIEWER_H
