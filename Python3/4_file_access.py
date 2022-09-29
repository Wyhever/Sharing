# -*- coding: utf-8 -*-
"""
Created on Tue May  3 22:16:03 2022

@author: Charlie
參考書籍: 第一次學Python 就上手 chapter5"
Python3
"""

#file access


"""
open(file, mode)
r: 讀取, 若檔案不存在則發生錯誤；預設值
w: 寫入，若檔案不存在則建立檔案
a: 附加，附加在檔案內容後面，若檔案不存在則建立檔案
r+: 讀取,以讀寫模式開啟檔案，檔案指標指向檔案開頭，寫入資料會覆蓋原本內容，若檔案不存在則發生錯誤；預設值
w+: 寫入，以讀寫模式開啟檔案並先清除檔案內容，若檔案不存在則建立檔案
w+: 附加，以讀寫模式開啟檔案，檔案指標指向檔案結尾，寫入資料會附加在檔案內容後面，若檔案不存在則建立檔案
"""
"Write file"
file = "test.txt"
#開啟檔案
fileObject = open(file,'w')
#寫入檔案
for i in range(5):
    fileObject.write(str(i) + ". Hello, World!\n")
fileObject.close()

"read() file"
fileObject = open(file,'r')

content = fileObject.read()
print(content)
#關閉檔案
fileObject.close()

"readline() file"
fileObject = open(file,'r')

line = fileObject.readline()
while line != "":
    print(line)
    line = fileObject.readline()
#關閉檔案
fileObject.close()


"readlines() file"
fileObject = open(file,'r')

content = fileObject.readlines()
print(content)
for line in content:
    print(line)
#關閉檔案
fileObject.close()

"check file is available"
import os.path
if os.path.isfile(file):
    fileObject = open(file,'r')

    content = fileObject.read()
    print(content)
    #關閉檔案
    fileObject.close()
else:
    print("file is not available!")    

"with funtion"
with open(file,'r') as fileObject:
    content = fileObject.read()
    print(content)