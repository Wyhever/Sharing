# -*- coding: utf-8 -*-
"""
Created on Thu Aug  4 21:44:52 2022

@author: Charlie
"""

import cv2
img = cv2.imread("Lena.jpg",0)
t1, thd = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
t2,ostu = cv2.threshold(img,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
cv2.imshow("img",img)
cv2.imshow("thd",thd)
cv2.imshow("ostu",ostu)
cv2.waitKey()
cv2.destroyAllWindows()
