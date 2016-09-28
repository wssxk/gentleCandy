#include <QApplication>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QScrollArea>
#include "mainWin.h"
#include "imgCell.h"
#include "imgTable.h"
#include "cellScroll.h"
#include "imgDownloader.h"
#include "imgViewer.h"

//#include "cpythonTest.h"

#include "crawler.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //imgCell ic;
    //ic.show();

    mainWin mw;
    mw.show();

    //imgViewer iv;
    //iv.show();

    //imgTable it;
    //it.show();
    //cellScroll cs;
    //cs.show();

    //imgDownloader id;
    //cpythonTest cpt;
    //getMainPage("test", 1);
    //getCatalogPython("jdlingyu", "http://www.jdlingyu.moe/14322/");

    return app.exec();
}
