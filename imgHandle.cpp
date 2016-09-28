#include <iostream>
//#include <string.h>
#include "imgHandle.h"
#include "crawler.h"

imgHandle::imgHandle(int st,
                     QString sg,
                     int pn,
                     QString si,
                     QString sit,
                     QString md)
                     //QObject* parent):QObject(parent)
{
    state = st;
    sign = sg;
    pageNum = pn;
    showImg = si;
    site = sit;
    modules = md;
}

int imgHandle::getState()
{
    return state;
}

QString imgHandle::getSign()
{
    return sign;
}

int imgHandle::getPage()
{
    return pageNum;
}

QString imgHandle::getShowImg()
{
    return showImg;
}

QString imgHandle::getSite()
{
    return site;
}

void imgHandle::setMainPage(QString moduleName, int page)
{
    state = 1;
    modules = moduleName;
    pageNum = page;
}

void imgHandle::setCatalog(QString catalogName, QString show, QString catalogSite)
{
    state = 2;
    sign = catalogName;
    showImg = show;
    site = catalogSite;
}


void imgHandle::setSingleImg(QString imgName, QString show, QString imgSite)
{
    state = 3;
    sign = imgName;
    showImg = show;
    site = imgSite;
}


//**爬取主页面内容，这里应通过调用python爬虫实现，考虑把调用python的过程封装成函数或类
QList<imgHandle>* imgHandle::getMainPage()
{
    //QList<imgHandle>* page = new QList<imgHandle>;
    //page->append(*(new imgHandle(3, "test1", -1, "http://www.sinaimg.cn/dy/slidenews/8_img/2016_38/199_207161_755554.jpg", "/home/wssxk/tmp/test1.jpg")));
    //page->append(*(new imgHandle(3, "test2", -1, "http://www.sinaimg.cn/dy/slidenews/3_img/2016_38/80965_397975_316336.jpg", "/home/wssxk/tmp/test2.jpg")));
    //page->append(*(new imgHandle(3, "test3", -1, "http://www.sinaimg.cn/dy/slidenews/3_img/2016_38/80965_397976_473360.jpg", "/home/wssxk/tmp/test3.jpg")));
    //page->append(*(new imgHandle(3, "test4", -1, "http://www.sinaimg.cn/dy/slidenews/3_img/2016_38/80965_397977_715385.jpg", "/home/wssxk/tmp/test4.jpg")));
    //page->append(*(new imgHandle(3, "test5", -1, "http://www.sinaimg.cn/dy/slidenews/3_img/2016_38/80965_397978_356761.jpg", "/home/wssxk/tmp/test5.jpg")));
    //page->append(*(new imgHandle(3, "test6", -1, "http://www.sinaimg.cn/dy/slidenews/5_img/2016_09/30939_1339702_403618.jpg", "/home/wssxk/tmp/test6.jpg")));
    //page->append(*(new imgHandle(3, "test7", -1, "http://www.sinaimg.cn/dy/slidenews/5_img/2016_09/30939_1339739_601574.jpg", "/home/wssxk/tmp/test7.jpg")));
    //page->append(*(new imgHandle(3, "test8", -1, "http://www.sinaimg.cn/dy/slidenews/5_img/2016_09/30939_1339705_516819.jpg", "/home/wssxk/tmp/test8.jpg")));
    //page->append(*(new imgHandle(3, "test9", -1, "http://www.sinaimg.cn/dy/slidenews/5_img/2016_09/30939_1339706_527498.jpg", "/home/wssxk/tmp/test9.jpg")));
    //std::cout << "pageSize" << page->size() << std::endl;
    return getMainPagePython(modules.toAscii().data(), pageNum);
}

QList<imgHandle>* imgHandle::getCatalog()
{
    return getCatalogPython(modules.toAscii().data(), site.toAscii().data());
}


imgHandle::imgHandle(const imgHandle& other)
{
    state = other.state;
    sign = other.sign;
    pageNum = other.pageNum;
    showImg = other.showImg;
    site = other.site;
    modules = other.modules;

}

imgHandle& imgHandle::operator =(const imgHandle& other)
{
    state = other.state;
    sign = other.sign;
    pageNum = other.pageNum;
    showImg = other.showImg;
    site = other.site;
    modules = other.modules;
    return *this;

}


void imgHandle::run()
{
    QList<imgHandle>* result;
    switch (state) {
    case 1:
        result = getMainPagePython(modules.toAscii().data(), pageNum);
        emit mainPageGetted(result);
        break;
    case 2:
        result = getCatalogPython(modules.toAscii().data(), site.toAscii().data());
        emit catalogGetted(result);
        break;
    case 3:
        break;
    default:
        break;
    }

}
