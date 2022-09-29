# -*- coding: utf-8 -*-
"""
Created on Tue May 10 22:35:20 2022

@author: Charlie
參考書籍: 第一次學Python 就上手 chapter14"
Python3
"""

import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0,5,0.1)
y = np.square(x)

plt.plot(x,y,"ro")
plt.plot(x,y,color = 'green', linestyle = 'dashed', marker = '+') # plt.plot(x,y,'g--+')

plt.axis([-5,10,-10,30]) 
#plt.xlim((-5,10))
#plt.ylim((-10,30)

plt.grid()

plt.xlabel("x value")
plt.ylabel("y value")

#x, y axis 刻度
#plt.xticks(np.arrange(5),("1","2","3","4","5"))
#plt.yticks(np.arrange(5),("1","2","3","4","5"))
# 顯示子刻度
#plt.minorticks_on()
# 取消子刻度
#plt.minorticks_off()

plt.title("y = x ** 2")
plt.text(-4,27,"y = x ** 2")
plt.plot(x,y,"bo", label = "y = x ** 2")
plt.legend()
plt.show()

#建立圖表
plt.figure(num = 1, figsize = (6,4), facecolor = 'lightblue')
plt.plot(x,y,"bo", label = "y = x ** 2")
plt.show()

#多張圖表
x = np.linspace(-10, 10, 100)
y1 = 20 * np.sin(x)
y2 = x * x * np.cos(x)

plt.subplot(211)
plt.plot(x,y1)
plt.subplot(212)
plt.plot(x,y2)
plt.show()

#bar plot
x = np.arange(0,100,10)
y = [15,26,13,34,30,24,45,64,15,5]
plt.bar(x = x, height = y, width = 5)
plt.title("bar plot")
plt.show()

#histogram plot
bins = x
plt.hist(y, bins, histtype = 'bar')
plt.show()

#pie plot
activities = ['A','B','B']
hours = [8,6,10]
colors = ['r','g','b']

plt.pie(hours, labels = activities, colors = colors, shadow =True, explode = (0,0.1,0), autopct = "%1.1f%%")
plt.axis('equal')
plt.show()


