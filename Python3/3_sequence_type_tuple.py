# -*- coding: utf-8 -*-
"""
Created on Sun May  1 16:39:25 2022

@author: Charlie
參考書籍: 第一次學Python 就上手 chapter5"
Python3
"""

#tuple: 一串不可改變、有順序的資料所組成
#用來存放不會變更的資料，tuple執行效率比list好

tuple1 = tuple((1,2,3))
tuple2 = ((1,2,3))
tuple3 = tuple("ABCDE")
tuple4 = tuple(range(5))
tuple5 = tuple([i * 20 for i in range(5)])
print(len(tuple5), max(tuple5), min(tuple5), sum(tuple5))

#不涉及改變元素的運算子皆適用於tuple
tuple6 = tuple1 + tuple3
tuple7 = tuple1 * 3
print(tuple1 == tuple2)
print('A' in tuple3)
print(tuple3[3])
print(tuple3[2:4])
print(tuple5.index(20))
print(tuple7.count(2))

sum = 0
for n in tuple5:
    sum+=n
    print(sum)