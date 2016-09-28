/*
 * imgViewer的实现函数
 */


#include <iostream>
#include "imgViewer.h"

imgViewer::imgViewer(imgHandle* hd)
{
    qsa = new QScrollArea;
    imgLabel = new QLabel;
    img = new QPixmap(":/refreshing.jpg");
    qgl = new QGridLayout;
    imgBuff = new QByteArray;
    showProgress = new QLabel;
    showProgress->clear();
    //imgSize = new QSize;
    handle = hd;

    isFinished = 0;

    imgTweak = new QSlider(Qt::Horizontal);
    qhbl = new QHBoxLayout;
    imgSave = new QPushButton("&Save");
    imgSave->setEnabled(false);
    QObject::connect(imgSave, SIGNAL(clicked()), this, SLOT(saveImg()));

    qsa->setAlignment(Qt::AlignCenter);
    imgTweak->setRange(1, 200);
    imgTweak->setValue(100);

    QObject::connect(imgTweak, SIGNAL(valueChanged(int)), this, SLOT(tweakValueChanged(int)));

    qhbl->insertStretch(1);
    qhbl->addWidget(showProgress);
    qhbl->addWidget(imgSave);
    qhbl->addWidget(imgTweak);

    if(hd != NULL)
        downloader = new imgDownloader(handle->getSite());
    else
        downloader = new imgDownloader;
    QObject::connect(downloader, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
    QObject::connect(downloader, SIGNAL(finished()), this, SLOT(finished()));
    QObject::connect(downloader, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));

    downloader->startDownload();

    imgLabel->setPixmap(*img);
    qsa->setWidget(imgLabel);
    qgl->addLayout(qhbl, 1, 1);
    qgl->addWidget(qsa, 2, 1);
    this->setLayout(qgl);
    this->resize(1200, 800);



}

imgViewer::~imgViewer()
{}

void imgViewer::downloadProgress(qint64 bytesRec, qint64 bytesTol)
{
    showProgress->clear();
    showProgress->setNum(bytesRec * 100.0 / bytesTol);
    //showProgress->setText("%");
    std::cout << bytesRec * 1.0 / bytesTol << ":" << bytesRec << ":" << bytesTol << std::endl;
    imgBuff->append(downloader->getData());
    img->loadFromData(*imgBuff);
    //*imgSize = img->size();
    imgLabel->setFixedSize(img->size());
    imgLabel->setPixmap(*img);

}

void imgViewer::finished()
{
    showProgress->clear();
    isFinished = 1;
    imgSave->setEnabled(true);
    //*imgSize = img->size();
    std::cout << "img Download finished" << std::endl;
}

void imgViewer::error(QNetworkReply::NetworkError code)
{}


void imgViewer::tweakValueChanged(int v)
{
    if(isFinished == 0)
    {
        imgTweak->setValue(100);
        return;
    }

    std::cout << "1" << std::endl;
    //*img = img->scaledToWidth(imgSize->width() * (v / 100.0));
    QPixmap tmpImg = img->scaledToWidth(img->width() * (v / 100.0));
    std::cout << "2" << std::endl;
    imgLabel->setFixedSize(tmpImg.size());
    imgLabel->setPixmap(tmpImg);

}


void imgViewer::saveImg()
{
    QString fileName = QDir::homePath();
    fileName.append("/gentleCandy/save/");

    QDir tmpDir;

    if(tmpDir.mkpath(fileName) == false)
    {
        std::cout << "mkpath failure" << std::endl;
        return;
    }

    fileName.append(handle->getSign());

    QFile file(fileName);

    if(file.exists() == true)
    {
        std::cout << "file exist" << std::endl;
    //    return;
    }

    if(file.open(QIODevice::WriteOnly) == false)
    {
        std::cout << "file open failure" << std::endl;
        return;

    }

    if(file.write(*imgBuff) == -1)
    {
        std::cout << "file write falure" << std::endl;
        return;

    }

    file.close();



}

