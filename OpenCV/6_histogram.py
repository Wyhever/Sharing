# -*- coding: utf-8 -*-
"""
Created on Sun Aug  7 16:09:23 2022

@author: Charlie
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt
#直方圖均化
img = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)
equ = cv2.equalizeHist(img)
cv2.imshow("original", img)
cv2.imshow("result", equ)
plt.figure("原始影像長條圖")
plt.hist(img.ravel(),256)
plt.figure("均橫化長條圖")
plt.hist(equ.ravel(),256)

cv2.waitKey()
cv2.destroyAllWindows()