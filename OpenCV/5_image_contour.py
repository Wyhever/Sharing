# -*- coding: utf-8 -*-
"""
Created on Sun Aug  7 15:22:55 2022

@author: Charlie
"""

import cv2
#形狀比對
o1 = cv2.imread('triangle.png',cv2.IMREAD_GRAYSCALE)
o2 = o = cv2.resize(o1, (128,128),interpolation = cv2.INTER_CUBIC)
o3 = cv2.imread('rectangle.png',cv2.IMREAD_GRAYSCALE)

ret, binary1 = cv2.threshold(o1, 127,255,cv2.THRESH_BINARY)
ret, binary2 = cv2.threshold(o2, 127,255,cv2.THRESH_BINARY)
ret, binary3 = cv2.threshold(o3, 127,255,cv2.THRESH_BINARY)

contours1, hierarchy = cv2.findContours(binary1, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
contours2, hierarchy = cv2.findContours(binary2, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
contours3, hierarchy = cv2.findContours(binary3, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

cnt1 = contours1[0]
cnt2 = contours2[0]
cnt3 = contours3[0]

ret0 = cv2.matchShapes(cnt1,cnt1,1,0.0)
ret1 = cv2.matchShapes(cnt1,cnt2,1,0.0)
ret2 = cv2.matchShapes(cnt1,cnt3,1,0.0)

print("相同影像:", ret0)
print("相似影像:", ret1)
print("不相同影像:", ret2)

#輪廓 Convex|Hull
h = cv2.imread('heart.png')
grayh = cv2.cvtColor(h, cv2.COLOR_BGR2GRAY)
ret, binaryh = cv2.threshold(grayh, 200,255,cv2.THRESH_BINARY)

contoursh, hierarchy = cv2.findContours(binaryh, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

hull = cv2.convexHull(contoursh[0])

cv2.polylines(h, [hull], True, (0,255,0),2)

cv2.imshow("result", h)
cv2.waitKey()
cv2.destroyAllWindows()

#計算形狀場景距離
flipHorizontal_h = cv2.flip(grayh, 1)
ret, binaryh_fliph = cv2.threshold(flipHorizontal_h, 200,255,cv2.THRESH_BINARY)
contoursh_fliph, hierarchy = cv2.findContours(binaryh_fliph, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

sd = cv2.createShapeContextDistanceExtractor()

d1 = sd.computeDistance(contoursh[0], contoursh[0])
print("與本身的距離",d1)
d2 = sd.computeDistance(contoursh[0], contoursh_fliph[0])
print("與翻轉後的本身的距離",d2)
d3 = sd.computeDistance(contoursh[0], contours1[0])
print("與不相似物件的距離",d3)

#計算Hausdorff距離
hd = cv2.createHausdorffDistanceExtractor()
d1 = hd.computeDistance(contoursh[0], contoursh[0])
print("與本身的Hausdorff距離",d1)
d2 = hd.computeDistance(contoursh[0], contoursh_fliph[0])
print("與翻轉後的本身的Hausdorff距離",d2)
d3 = hd.computeDistance(contoursh[0], contours1[0])
print("與不相似物件的Hausdorff距離",d3)