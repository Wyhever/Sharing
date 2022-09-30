# -*- coding: utf-8 -*-
"""
Created on Sat Aug  6 21:31:12 2022

@author: Charlie
"""

import cv2
#Canny邊緣檢測
o = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)
r1 = cv2.Canny(o,128,200)
r2 = cv2.Canny(o,32,128)
cv2.imshow("o",o)
cv2.imshow("r1",r1)
cv2.imshow("r2",r2)
cv2.waitKey()
cv2.destroyAllWindows()