# -*- coding: utf-8 -*-

import mainPage
import catalog




def getMainPage(pageNum):
    p = int(pageNum[0]);
    result = ();
    for i in range(p * 4 - 3, p * 4 + 1):
        result += mainPage.mainPage(i);
    return result;

def getCatalog(site):
    url = '';
    for i in site:
        url += i;
    return catalog.catalog(url);
    

#t1 = 'http://www.jdlingyu.moe/14322/'
#t2 = ();
#for t3 in t1:
#    t2 += (t3,);

#print(t2);

#print(getCatalog(t2));

#print(getMainPage(2));
