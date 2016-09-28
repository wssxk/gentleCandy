# -*- coding: utf-8 -*-


#返回类型
#((int state, bytearray sign, int pageNum, bytearray showimg, bytearray site), ...)

import urllib.request

def getImg(imgId):
    #url = 'http://safebooru.org/index.php?page=post&s=view&id=' + imgId;
    content2 = urllib.request.urlopen('http://safebooru.org/index.php?page=post&s=view&id=' + imgId);
    print("content 2 get");
    s = content2.read();
    s = str(s, 'utf-8', 'ignore');
    #f = open('contentuuuu.html', 'w');
    #f.write(s);
    #f.close();
    pos1 = s.find('<img alt=');
    pos1 = s.find('src="', pos1);
    pos2 = s.find('?', pos1);
    img = s[pos1 + 5:pos2];
    #print(img);
    return img;
    


def mainPage(pageNum):
    count = 1;
    
    pid = (pageNum - 1) * 40;

    content = urllib.request.urlopen('http://safebooru.org/index.php?page=post&s=list&pid=' + str(pid));

    print("get");

    s = content.read();
    s = str(s, 'utf-8', 'ignore');

    #f1 = open('content.html', 'w');
    #f2 = open('content2.html', 'w');
    #f1.write(s);
    #f2.write(str(content.read()));
    #f1.close();
    #f2.close();
    #print(s);

    #pos1 = s.find('class="thumb"');

    result = ();
    pos1 = 0;
    pos2 = len(s);
    while True:
        pos1 = s.find('class="thumb"', pos1);
        if pos1 == -1:
            print('here');
            break;
        pos2 = s.find('" href', pos1);
        name = s[pos1 + 21:pos2];
        pos1 = s.find('<img src=', pos2);
        pos2 = s.find('?', pos1);
        showImg = s[pos1 + 10: pos2];
        #print(name + ":::" + showImg);
        site = getImg(name[1:]);
        #site = 'http://safebooru.org//samples/1756/sample_d8b9876f882ea24bfcfbca5f67ef9ceb79be82ee.png';
        if '.' not in site[-7:]:
            continue;
        
        imgName = site[::-1];
        imgNamePos = imgName.find('/');
        imgName = imgName[:imgNamePos];
        imgName = imgName[::-1];
        print('imgName::' + imgName);
        imgName = bytearray(imgName, 'utf-8', 'ignore');

        print('showImg::' + showImg);
        showImg = bytearray(showImg, 'utf-8', 'ignore');
        print('site::' + site);
        site = bytearray(site, 'utf-8', 'ignore');


        
        print('count ::' + str(count));
        count += 1;
        result += ((3, imgName, -1, showImg, site),);
        
    print('Finished');
    return result;
        



#mainPage(1);
