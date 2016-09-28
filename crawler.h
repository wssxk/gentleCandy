#ifndef CRAWLER_H
#define CRAWLER_H

#include <QList>
#include "imgHandle.h"

QList<imgHandle>* getMainPagePython(char* name, int page);

QList<imgHandle>* getCatalogPython(char* module, char* site);



#endif // CRAWLER_H
