# -*- coding: utf-8 -*-
"""
Created on Sun May  1 16:54:29 2022

@author: Charlie
參考書籍: 第一次學Python 就上手 chapter5"
Python3
"""

#tuple: 一串可改變、沒有順序、沒有重複的資料所組成
#set執行效率比list好

set1 = set()
set2 = set({1,2,3})
set3 = set('ABCDE')
set4 = set('ABCDA')
set5 = set(range(5))
set6 = set([i ** 2 for i in range(10)])

print(len(set6), max(set6), min(set6), sum(set6))

print('A' in set3)

#set運算子: 集合
print('===== set operator =====')
S1 = {"A","B","C"}
S2 = {"D","A","B","C"}
S3 = {"C","A","B"}
S6 = {'X','Y','Z'}

print(S1 == S3)            #S1和S3包含相同元素
print(S1 != S2)            #S1和S2包含不同元素
print(S1 <= S2)            #S1是S2子集合
print(S1.issubset(S2))     #S1是S2子集合嗎?
print(S1 < S2)             #S1是S2真子集合
print(S1 >= S2)            #S1不是S2超集合
print(S1.issuperset(S2))   #S1是S2超集合嗎?
print(S1 > S2)             #S1不是S2真超集合
print(S2 > S3)             #S2是S3超集合
print(S2 >= S3)            #S2是S3真超集合

print(S1.isdisjoint(S6))   #S1和S6沒有相同元素嗎?
#聯集
S7 = S1.union(S6)          #S1和S6取聯集；S7 = S1|S6
S1.update(S6)              #S1和S6取聯集後更新S1
#交集
S8 = S3.intersection(S2)   #S3與S2取交集；S8 = S3&S2
S3.intersection_update(S2) #S3和S2取交集後更新S3
#差集
S1 = {"A","B","C"}
S2 = {"D","A","B","C"}
S9 = S1.difference(S2)     #S1和S2取差集；S9 = S1-S2
S1.difference_update(S2)   #S1和S2取差集後更新S1

#對稱差集(互斥)
S1 = {"A","B","C"}
S2 = {"D","A","B","C"}
S9 = S1.symmetric_difference(S2)     #S1和S2取對稱差集；S10 = S1^S2
S1.symmetric_difference_update(S2)             #S1和S2取對稱差集後更新S1

print('==========')

sum = 0
for n in set6:
    sum+=n
    print(sum)
    
S4 = {1,2,3,4,5,6}
S4.add(60)
S4.remove(6)
print(S4.pop())# 刪除一個元素並回傳該值
S5 = S4.copy()
S4.clear()
