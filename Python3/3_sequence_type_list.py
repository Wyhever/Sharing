# -*- coding: utf-8 -*-
"""
Created on Sat Apr 30 17:15:58 2022

@author: Charlie
參考書籍: 第一次學Python 就上手 chapter5"
Python3
"""

#list: 一串可改變、有順序的資料所組成
list1 = list()
list2 = []
list3 = list("ABCD")
list3_1 = ["ABCD"]
list4 = list(range(5))
list5 = list(range(10, 0, -2))
list6 = "1 2 3".split()
list7 = "1,2,,3".split(',')

list_num_str = list4 + list3
list8 = list6 * 3

print("A" in list3)
print("a" not in list3)

list9 = list(range(0,50,5))
print(list9[3:6])
print(list9[6:-1])

sum = 0
for num in list9:
    sum+=num
    print(sum)    

#list: append, extend, insert, remove, pop
print(list4)
list4.append(5)
print(list4)
list4.extend(list9)
print(list4)
list4.insert(1, -1)
print(list4)
list4.remove(-1)
print(list4.pop())
print(list4)
#list: index, count, sort, reverse, copy, clear
print(list4.index(20))
print(list4.count(0))
list4.sort()
print(list4)
list4.reverse()
print(list4)
list4_copy = list4.copy()
list4.clear()
print(list4)

#list comprehension
list4_10up = [list4_copy[i] for i in range(len(list4_copy)) if list4_copy[i] > 10]
del list4_10up[0]

#2D list (nested list)
grades = [[100,90,95],[60,90,90],[80,75,95],[70,80,80]]
for student in range(len(grades)):
    points = 0
    for p in range(len(grades[student])):
        points += grades[student][p]
    grades[student].append(points)
for student in range(len(grades)):
    print("student",student+1, " get points:", grades[student][3])
    
        
