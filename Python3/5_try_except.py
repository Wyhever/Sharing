# -*- coding: utf-8 -*-
"""
Created on Thu May  5 22:44:53 2022

@author: Charlie
參考書籍: 第一次學Python 就上手 chapter5"
Python3
"""

try:
    x = eval(input("請輸入被除數X: "))
    y = eval(input("請輸入除數Y: "))
    z = x/y
except ZeroDivisionError:
    print("除數不得為0")
except Exception as e1:
    print(e1.args)
else:
    print("沒有發生例外，X除以Y等於",z)
finally:
    print("離開try...except區塊10")
    
    
#自行丟出例外
try:
    raise NameError("ThisisError")
except NameError:
    print("捕捉到NameError")
