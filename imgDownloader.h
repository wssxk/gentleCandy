/*
 * 下载图片的类
 */

#ifndef IMGDOWNLOADER_H
#define IMGDOWNLOADER_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QByteArray>
#include <QPixmap>

class imgDownloader:public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager* networkManager;
    QNetworkReply* reply;
    QNetworkRequest* request;
    QString url;
public:
    imgDownloader(QString u = "");
    //imgDownloader(QString u, QString fp);
    QByteArray getData();   //获取当前已下载数据
    void setUrl(QString u);

public slots:
    void startDownload();
    //void restartDownload();

signals:
    void finished();
    void downloadProgress(qint64 bytesRec, qint64 bytesTol);
    void error(QNetworkReply::NetworkError code);
};

#endif // IMGDOWNLOADER_H
