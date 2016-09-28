# -*- coding: utf-8 -*-

import mainPage

def getMainPage(pageNum):
    print('getMainPage');
    p = int(pageNum[0]);
    return mainPage.mainPage(p);
    

def getCatalog(site):
    pass

#getMainPage(('1'));