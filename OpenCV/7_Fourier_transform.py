# -*- coding: utf-8 -*-
"""
Created on Sun Aug  7 19:44:54 2022

@author: Charlie
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt
# Numpy: fourier transform 高通濾波，保留影像邊緣資訊
img = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)
f =np.fft.fft2(img)
fshift = np.fft.fftshift(f)
rows, cols = img.shape
crow, ccol = int(rows/2), int(cols/2)
fshift[crow-30:crow+30,ccol-30:ccol+30] = 0
ishift = np.fft.ifftshift(fshift)
iimg = np.fft.ifft2(ishift)
iimg = np.abs(iimg)

plt.subplot(121),plt.imshow(img, cmap = 'gray')
plt.title('original'), plt.axis('off')
plt.subplot(122),plt.imshow(iimg, cmap = 'gray')
plt.title('iimg'), plt.axis('off')
plt.show()

# OpenCV: fourier transform 低通濾波:削弱影像邊緣資訊
img = cv2.imread('lena.jpg',cv2.IMREAD_GRAYSCALE)
f =np.fft.fft2(img)
dft = cv2.dft(np.float32(img), flags = cv2.DFT_COMPLEX_OUTPUT)
dftshift = np.fft.fftshift(dft)
rows, cols = img.shape
crow, ccol = int(rows/2), int(cols/2)
mask = np.zeros((rows, cols,2), np.uint8)
mask[crow-30:crow+30,ccol-30:ccol+30] = 1

fShift = dftshift*mask
iShift = np.fft.ifftshift(fShift)
iImg = cv2.idft(iShift)
iImg = cv2.magnitude(iImg[:,:,0],iImg[:,:,1])

plt.subplot(121),plt.imshow(img, cmap = 'gray')
plt.title('original'), plt.axis('off')
plt.subplot(122),plt.imshow(iImg, cmap = 'gray')
plt.title('iimg'), plt.axis('off')
plt.show()
