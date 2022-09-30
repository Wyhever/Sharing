# -*- coding: utf-8 -*-
"""
Created on Mon Aug  8 21:39:52 2022

@author: Charlie
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt
# 旋轉angle角度，缺失背景白色（255, 255, 255）填充
def rotate_bound_white_bg(image, angle):
    # grab the dimensions of the image and then determine the
    # center
    (h, w) = image.shape[:2]
    (cX, cY) = (w // 2, h // 2)
 
    # grab the rotation matrix (applying the negative of the
    # angle to rotate clockwise), then grab the sine and cosine
    # (i.e., the rotation components of the matrix)
    # -angle位置引數為角度引數負值表示順時針旋轉; 1.0位置引數scale是調整尺寸比例（影象縮放引數），建議0.75
    M = cv2.getRotationMatrix2D((cX, cY), -angle, 1.0)
    cos = np.abs(M[0, 0])
    sin = np.abs(M[0, 1])
 
    # compute the new bounding dimensions of the image
    nW = int((h * sin) + (w * cos))
    nH = int((h * cos) + (w * sin))
 
    # adjust the rotation matrix to take into account translation
    M[0, 2] += (nW / 2) - cX
    M[1, 2] += (nH / 2) - cY
 
    # perform the actual rotation and return the image
    # borderValue 缺失背景填充色彩，此處為白色，可自定義
    return cv2.warpAffine(image, M, (nW, nH),borderValue=(255,255,255))
    # borderValue 預設，預設是黑色（0, 0 , 0）
    # return cv2.warpAffine(image, M, (nW, nH))

img = cv2.imread('Sudoku.png')
img = rotate_bound_white_bg(img, 45)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

edges = cv2.Canny(gray,50,150,apertureSize = 3)
orgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
oshow = orgb.copy()
#霍夫轉換
lines = cv2.HoughLines(edges,1,np.pi/180,140)
#機率霍夫轉換
linesP = cv2.HoughLinesP(edges,1,np.pi/180,1, minLineLength=100, maxLineGap =10)
for line in lines:
    rho, theta = line[0]
    a = np.cos(theta)
    b = np.sin(theta)
    x0 = a*rho
    y0 = b*rho
    x1 = int(x0+1000*(-b))
    y1 = int(y0+1000*(a))
    x2 = int(x0-1000*(-b))
    y2 = int(y0-1000*(a))
    cv2.line(orgb, (x1,y1),(x2,y2),(0,0,255),2)

plt.subplot(121),plt.imshow(oshow)
plt.title('original image'), plt.axis('off')
plt.subplot(122),plt.imshow(orgb)
plt.title('Hough lines'), plt.axis('off')
plt.show()

orgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
for line in linesP:
    x1,y1,x2,y2 = line[0]
    cv2.line(orgb, (x1,y1),(x2,y2),(255,0,0),2)
plt.subplot(121),plt.imshow(oshow)
plt.title('original image'), plt.axis('off')
plt.subplot(122),plt.imshow(orgb)
plt.title('Probability Hough lines'), plt.axis('off')
plt.show()