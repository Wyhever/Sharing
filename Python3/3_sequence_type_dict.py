# -*- coding: utf-8 -*-
"""
Created on Mon May  2 16:45:16 2022

@author: Charlie
參考書籍: 第一次學Python 就上手 chapter5"
Python3
"""

#dict: 可改變、沒有順序、沒有重複的多個鍵:質對，屬於對映型別，已鍵作為索引存取字典裡的值
#create dict
dict1 = {"ID":"00001","name":"A"}
dict1_1 = {"name":"A","ID":"00001"}
print(dict1 == dict1_1)

a = {"one":1,"two":2,"three":3}
b = dict(a)
c = dict(one = 1, two = 2, three = 3)

#get, add, edit, remove key: value pair

x = a["one"]
a["four"] = 4
a["four"] = "IV"
del a["four"]

print(len(a))
print("one" in a)
print("five" not in a)

#operator
print("===== dict operator =====")
d1 = {"fruit1": "apple", "fruit2": "banana", "fruit3": "orange"}
d2 = {"fruit1": "apple", "fruit2": "banana", "fruit3": "orange","fruit4":"watermalon"}
d3 = {"fruit3": "orange", "fruit1": "apple", "fruit2": "banana"}

print(d1 == d2)
print(d1 == d3)
print(d2 != d3)
print(d1 is d3)
print("==========")

for key in d1:
    print("key is", key, ",corresponding value is", d1[key] )

#processing way

print(d1.get("fruit1"))
print(d1.pop("fruit1"),"processed dict:" ,d1)  # 刪除鍵為fruit1的鍵:值對，並回傳值
print(d1.popitem(),"processed dict:", d1)      # 刪除一個隨機鍵:值對，並回傳值
print("=====dict.k_v_i()=====")
print(d2.keys())
print(d2.values())
print(d2.items())
print("===== dict.copy() =====")
d4 = d2.copy()
print(d4 == d2)
print(d4 is d2)
print(d4.clear())
d4 = {"fruit4": "pineapple", "fruit1": "strawberry", "fruit2": "banana"}
d3.update(d4)       #根據新dict4更新舊dict3，若有重複鍵，以新dict的鍵:值取代