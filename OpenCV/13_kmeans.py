# -*- coding: utf-8 -*-
"""
Created on Thu Aug 11 21:45:46 2022

@author: Charlie
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt
#訓練資料
rankA = np.random.randint(0,20,(30,2)).astype(np.float32)
rankB = np.random.randint(50,70,(30,2)).astype(np.float32)

data = np.vstack((rankA, rankB))
data = np.array(data,dtype = 'float32')

#設定criteria值
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
#呼叫kmeans，計算標籤與類別中心點
ret, label, center = cv2.kmeans(data, 2, None, criteria, 10, cv2.KMEANS_RANDOM_CENTERS)

print(ret)
print(label)
print(center)

a = data[label.ravel()==0]
b = data[label.ravel()==1]
#散佈圖
plt.scatter(a[:,0], a[:,1],80,'g','o')
plt.scatter(b[:,0], b[:,1],80,'r','s')
plt.scatter(center[0,0], center[0,1],80,'b','*')
plt.scatter(center[1,0], center[1,1],80,'b','*')
plt.show()

