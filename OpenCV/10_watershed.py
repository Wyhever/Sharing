# -*- coding: utf-8 -*-
"""
Created on Tue Aug  9 21:31:45 2022

@author: Charlie
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt
# 分水嶺演算法
img = cv2.imread('coin.jpg')
#img = cv2.resize(img, (504,624),interpolation = cv2.INTER_CUBIC)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# cv2.imshow("gray", gray)
# cv2.waitKey()
# cv2.destroyAllWindows()

img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
ishow = img.copy()

ret, threshold =  cv2.threshold(gray,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

kernel = np.ones((3,3),np.uint8)

opening = cv2.morphologyEx(threshold,cv2.MORPH_OPEN,kernel, iterations = 2)

sure_bg = cv2.dilate(opening,kernel,iterations=3)

dist_transform = cv2.distanceTransform(opening, cv2.DIST_L2,5)

ret, sure_fg = cv2.threshold(dist_transform,0.7*dist_transform.max(),255,0)
sure_fg = np.uint8(sure_fg)
unknown = cv2.subtract(sure_bg, sure_fg)

ret, markers = cv2.connectedComponents(sure_fg)
markers = markers +1
markers[unknown==255] = 0
markers = cv2.watershed(img, markers)

img[markers == -1] = [0,255,0]

plt.subplot(121),plt.imshow(ishow)
plt.title('original image'), plt.axis('off')
plt.subplot(122),plt.imshow(img)
plt.title('image segmentation'), plt.axis('off')
plt.show()