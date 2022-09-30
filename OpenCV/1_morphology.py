# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import cv2
import numpy as np
#梯度運算
j = cv2.imread("j.png",cv2.IMREAD_UNCHANGED)
k = np.ones((5,5), np.uint8)
r = cv2.morphologyEx(j, cv2.MORPH_GRADIENT,k)
cv2.imshow("original",j)
cv2.imshow("result",r)
cv2.waitKey()
cv2.destroyAllWindows()

#禮帽運算
lena = cv2.imread("lena.jpg",cv2.IMREAD_GRAYSCALE)
k = np.ones((5,5), np.uint8)
r = cv2.morphologyEx(lena, cv2.MORPH_TOPHAT,k)
cv2.imshow("original",lena)
cv2.imshow("result",r)
cv2.waitKey()
cv2.destroyAllWindows()

#黑帽運算
lena = cv2.imread("lena.jpg",cv2.IMREAD_GRAYSCALE)
k = np.ones((5,5), np.uint8)
r = cv2.morphologyEx(lena, cv2.MORPH_BLACKHAT,k)
cv2.imshow("original",lena)
cv2.imshow("result",r)
cv2.waitKey()
cv2.destroyAllWindows()
