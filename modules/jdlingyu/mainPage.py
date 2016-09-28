# -*- coding: utf-8 -*-

#返回类型
#((int state, bytearray sign, int pageNum, bytearray showimg, bytearray site), ...)

import urllib.request 

def mainPage(pageNum):

 
    #获取html
    content = urllib.request.urlopen('http://www.jdlingyu.moe/page/' + str(pageNum));
    
    
    #记录索引
    #indexAll = [];
    result = ();
    
    #提取并转换索引
    for t in content:
     #   print(t);
        s = str(t, 'utf-8', 'ignore');
        break;
    #s1 = content.decode('GBK', 'ignore');
    #print(s1);
    #f.write(s);
    #f.close();
   
    pos1 = 0;
    
    #提取具体信息
    while True:
        print("here");
        tmp = [];
        
        #编号
        pos1 = s.find('<div id="pin-', pos1);
        if pos1 == -1: break;
        pos1 = s.find('pin-', pos1);
        pos2 = s.find('"', pos1);
        #tmp.append(s[pos1:pos2]);
        identify = s[pos1:pos2];
        #print(s[pos1:pos2]);
        
        #对应页面地址
        pos1 = s.find('http://www.jdlingyu.moe/', pos1);
        pos2 = s.find("'", pos1);
        site = bytearray(s[pos1:pos2-1], 'utf-8', 'ignore');
        #tmp.append(s[pos1:pos2 - 1]);
        #print(s[pos1:pos2-1]);
        
        #展示图片路径
        pos1 = s.find('http://www.jdlingyu.moe/wp-content/uploads/thumbnail/', pos1);
        pos2 = s.find("'", pos1);
        show = bytearray(s[pos1:pos2], 'utf-8', 'ignore');
        #tmp.append(s[pos1:pos2]);
    
        #名称
        pos1 = s.find("alt='", pos1) + 5;
        pos2 = s.find("'", pos1);
        sign = bytearray(s[pos1:pos2], 'utf-8', 'ignore');
        #tmp.append(s[pos1:pos2]);     
        
        result += ((2, sign, -1, show, site),);
        #indexAll.append(tmp);
        #break
    print(len(result));
    print(type(result));

    return result;    
    #print(indexAll);

#print(mainPage(1));

