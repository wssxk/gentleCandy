# -*- coding: utf-8 -*-


import urllib.request
import os

def catalog(url):
    print(url);
    s = urllib.request.urlopen(url).read();
    s = str(s, 'utf-8', 'ignore');
   
   #print('Done');    
    #url = lst[1];
    #print(url);
    #获取页面数据
    #s = urllib.request.urlopen(url).read();
    #s = str(s, 'utf-8', 'ignore');
    
    img = ();
    
    pos1 = s.find('"main-body"');
    pos2 = s.find('"main-tags"');
    #print('TTT');
    #f = open('content.html', 'w');
    #f.write(s);
    #return;
    #提取图片地址
    #modules = bytearray("jdlingyu", 'utf-8', 'ignore');
    #sign = bytearray('noName');
    while True:
        pos1 = s.find('<a href="', pos1, pos2);
        #print(pos1);
        if pos1 == -1: break;        
        pos1 += 9;
        pos3 = s.find('"', pos1);
        #print(s[pos1:pos3]);
        #img.append(s[pos1:pos3]);
        tmp = s[pos1:pos3];
        if '.' not in tmp[-5:]:
            print('not a pic : ' + tmp);
            continue;
        #获取图片名称
        sign = tmp[::-1];
        signPos = sign.find('/');
        sign = sign[:signPos];
        sign = sign[::-1];
        sign = bytearray(sign, 'utf-8', 'ignore');

        tmp = bytearray(tmp, 'utf-8', 'ignore');
        img += ((3, sign, -1, tmp, tmp),);

    print(img);
    return img;


#getCatalog('http://www.jdlingyu.moe/14322/');

'''    
    count = 1;
    
    for t1 in img:
        print(t1);
    
    
    for t1 in img:
        #检测是否为图片链接
        if '.' not in t1[-5:]:
            print('error not a pic' + t1);
            continue;
        #检测图片是否已下载
        if str(count) + '.jpg' in os.listdir(saveDir + lst[3]):
            print('file exist: ' + str(count) + '.jpg');
            count += 1;
            continue;
        #下载图片
        try:
            urllib.request.urlretrieve(t1, dirName + str(count) + '.jpg');
            print('Done');        
        except:
            print("error " + t1);
            isError = 1;
        
        count += 1;
'''
