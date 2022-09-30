# -*- coding: utf-8 -*-
"""
Created on Thu Aug 11 21:33:24 2022

@author: Charlie
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt
#訓練資料
rankA = np.random.randint(95,100,(20,2)).astype(np.float32)
rankB = np.random.randint(90,95,(20,2)).astype(np.float32)

data = np.vstack((rankA, rankB))
data = np.array(data,dtype = 'float32')
#標籤
aLabel = np.zeros((20,1)).astype(np.float32)
bLabel = np.ones((20,1)).astype(np.float32)
label = np.vstack((aLabel, bLabel))
label = np.array(label,dtype = 'int32')

svm = cv2.ml.SVM_create()
# 屬性設定
#svm.setType(cv2.ml.SVM_C_SVC)
#svm.setKernel(cv2.ml.SVM_LINEAR)

result = svm.train(data, cv2.ml.ROW_SAMPLE,label)
#測試資料
test = np.vstack([[98,90],[90,99]])
test = np.array(test,dtype = 'float32')
#預測結果
(p1,p2) = svm.predict(test)

plt.scatter(rankA[:,0], rankA[:,1],80,'g','o')
plt.scatter(rankB[:,0], rankB[:,1],80,'b','s')
plt.scatter(test[:,0], test[:,1],80,'r','*')
plt.show()

print(test)
print(p2)

