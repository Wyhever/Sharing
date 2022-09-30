# -*- coding: utf-8 -*-
"""
Created on Sat Aug  6 21:37:59 2022

@author: Charlie
"""

import cv2
import numpy as np
#Canny邊緣檢測
o = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)
o = cv2.resize(o, (512,512),interpolation = cv2.INTER_CUBIC)
G0= o
G1 = cv2.pyrDown(G0)
G2 = cv2.pyrDown(G1)
G3 = cv2.pyrDown(G2)
#拉普拉斯金字塔
L0 = G0-cv2.pyrUp(G1)
L1 = G1-cv2.pyrUp(G2)
L2 = G2-cv2.pyrUp(G3)

print("L0 shape", L0.shape)
print("L1 shape", L1.shape)
print("L2 shape", L2.shape)

cv2.imshow("L0",L0)
cv2.imshow("L1",L1)
cv2.imshow("L2",L2)

cv2.waitKey()
cv2.destroyAllWindows()
#透過拉普拉絲影像復原的原始影像
R0 = L0+cv2.pyrUp(G1)
print("o shape", o.shape)
print("R0 shape", R0.shape)

result = abs(R0-o)

print("計算原始影像與恢復影像的差值: ",np.sum(result))
