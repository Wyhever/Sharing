# -*- coding: utf-8 -*-
"""
Created on Sat Aug  6 15:03:14 2022

@author: Charlie
"""

import cv2
#Sobel邊緣檢測
o = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)
sobelx = cv2.Sobel(o,cv2.CV_64F,1,0)
sobely = cv2.Sobel(o,cv2.CV_64F,0,1)
sobelx = cv2.convertScaleAbs(sobelx)
sobely = cv2.convertScaleAbs(sobely)
sobelxy = cv2.addWeighted(sobelx,0.5,sobely,0.5,0)
sobelxy11 = cv2.Sobel(o,cv2.CV_64F,1,1)
sobelxy11 = cv2.convertScaleAbs(sobelxy11)
cv2.imshow('original',o)
cv2.imshow('sobelxy',sobelxy)
cv2.imshow('sobelxy11',sobelxy11)
cv2.waitKey()
cv2.destroyAllWindows()

#Sobel邊緣檢測
o = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)
scharrx = cv2.Scharr(o,cv2.CV_64F,1,0)
scharry = cv2.Scharr(o,cv2.CV_64F,0,1)
scharrx = cv2.convertScaleAbs(scharrx)
scharry = cv2.convertScaleAbs(scharry)
scharrxy = cv2.addWeighted(scharrx,0.5,scharry,0.5,0)
cv2.imshow('original',o)
cv2.imshow('scharr',scharrxy)
cv2.waitKey()
cv2.destroyAllWindows()


#Sobel邊緣檢測
o = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)
laplacian = cv2.Laplacian(o,cv2.CV_64F)
laplacian = cv2.convertScaleAbs(laplacian)
cv2.imshow('original',o)
cv2.imshow('laplacian',laplacian)
cv2.waitKey()
cv2.destroyAllWindows()