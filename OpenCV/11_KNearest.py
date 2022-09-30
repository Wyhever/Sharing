# -*- coding: utf-8 -*-
"""
Created on Wed Aug 10 21:50:29 2022

@author: Charlie
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt

rand1 = np.random.randint(0,30,(20,2)).astype(np.float32)

rand2 = np.random.randint(70,100,(20,2)).astype(np.float32)
#訓練資料
trainData = np.vstack((rand1, rand2))
#資料標籤
r1Label = np.zeros((20,1)).astype(np.float32)
r2Label = np.ones((20,1)).astype(np.float32)
tdLabel = np.vstack((r1Label, r2Label))

g = trainData[tdLabel.ravel() == 0]
plt.scatter(g[:,0], g[:,1],80,'g','o')

b = trainData[tdLabel.ravel() == 1]
plt.scatter(b[:,0], b[:,1],80,'b','s')
#測試資料
test =  np.random.randint(0,100,(1,2)).astype(np.float32)
plt.scatter(test[:,0], test[:,1],80,'r','*')
#呼叫knearest
knn = cv2.ml.KNearest_create()
knn.train(trainData, cv2.ml.ROW_SAMPLE, tdLabel)
#測試結果
ret, result, neighbours, dist = knn.findNearest(test, 5)
print("亂數判斷結果:", result)
print("距離最近的5個點:", neighbours)
print("距離最近5個點的距離:", dist)

plt.show()

