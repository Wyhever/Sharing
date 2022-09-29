# -*- coding: utf-8 -*-
"""
Created on Mon May  9 22:47:57 2022

@author: Charlie
參考書籍: 第一次學Python 就上手 chapter13"
Python3
"""

from PIL import Image as image, ImageDraw, ImageFont
from PIL import ImageFilter as imfilter
#open image
im = image.open("Lenna.png")
im.show()
print(im.format, im.size)
#convert image
out = im.convert("1")
out.show()
grey = im.convert("L")
grey.show()
#rotate and flip image
grey_45 = grey.rotate(45)
grey_45.show()

grey_flip = grey.transpose(image.FLIP_LEFT_RIGHT)
grey_flip.show()

#image filter
#blur image
im_blur = im.filter(imfilter.BLUR)
im_blur.show()

#space image
new_im = image.new("RGB",(400,400))
draw = ImageDraw.Draw(new_im)
# draw a circle
draw.ellipse([(100,100),(300,300)], fill = (0,255,0,255))
# draw a text
ttfont = ImageFont.truetype("C:\\Windows\\Fonts\\Arial\\arial.ttf",50)
draw.text((150,10),"circle", font = ttfont, fill = (255,0,0,255))
new_im.show()
#rezie image
im_resize = new_im.resize((400,200))
im_resize.show()