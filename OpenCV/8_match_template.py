# -*- coding: utf-8 -*-
"""
Created on Mon Aug  8 21:24:08 2022

@author: Charlie
"""

import cv2
import matplotlib.pyplot as plt
# 範本比對
img = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)

img = cv2.resize(img, (512,512),interpolation = cv2.INTER_CUBIC)
template = img[250:300, 200:300]

th, tw = template.shape[::]

rv = cv2.matchTemplate(img, template, cv2.TM_SQDIFF)
minVal, maxVal, minLoc, maxLoc = cv2.minMaxLoc(rv)
topLeft = minLoc
bottomRight = (topLeft[0]+tw,topLeft[1]+th)
cv2.rectangle(img, topLeft, bottomRight,255,2)

plt.subplot(121),plt.imshow(rv, cmap = 'gray')
plt.title('matching result'), plt.axis('off')
plt.subplot(122),plt.imshow(img, cmap = 'gray')
plt.title('detected point'), plt.axis('off')
plt.show()