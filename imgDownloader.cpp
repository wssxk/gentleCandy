#include "imgDownloader.h"

imgDownloader::imgDownloader(QString u)
{
    url = u;
    networkManager = new QNetworkAccessManager;
    reply = NULL;
    request = new QNetworkRequest(QUrl(url));
}

/*
imgDownloader::imgDownloader(QString u, QString fp)
{


}
*/

QByteArray imgDownloader::getData()
{
    if(reply == NULL) return QByteArray();
    return reply->readAll();
}

void imgDownloader::setUrl(QString u)
{
    url = u;
}

void imgDownloader::startDownload()
{
    //delete reply;
    //reply = new QNetworkReply;

    request->setUrl(QUrl(url));
    reply = networkManager->get(*request);

    QObject::connect(reply, SIGNAL(finished()), this, SIGNAL(finished()));
    QObject::connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));
    QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SIGNAL(error(QNetworkReply::NetworkError)));

}
