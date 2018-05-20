# 4 types (modes) of digital image
# 003.py

# =======================================================================
# Overview
# =======================================================================

# 1. binary image : 이진영상
# 1. color image : 회색음영영상
# 1. grayscale image : 칼라영상
# 1. multi-spectral image : 다중스펙트럼영상

# =======================================================================
# binary image
# =======================================================================

# Binary image can use only white and black to express light intensity
# One pixel requires 1 bit
# Binary image is not much used these days
# Binary image was used for OCR, inspecting shape, inspecting contour

# You can see grayscale image
# img 2018-05-20 13-55-49.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 13-55-49.png"><xmp>

# Right images are binary images

# 1st binary image was mady by using threshholding to convert grayscale image into binary image,
# removing many information that sheep has like texture of brush

# 2nd binary image is better than 1st binary image
# 2nd binary image was made by using dithering, which uses density of dots to control brightness
# Dim area has high density

# Dithering is for displaying on screen
# Halftoning is for printing on paper, manipulating size of dot unlike dithering manipulates density of dots
# img 2018-05-20 13-56-11.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 13-56-11.png"><xmp>

# You can apply halftoning to color printing as well as binary image printing
# img 2018-05-20 13-58-15.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 13-58-15.png"><xmp>

# =======================================================================
# grayscale image
# =======================================================================

# Grayscale image uses white, black, dim white(gray), dim black (gray)

# grayscale image can collaborate with quantization

# Generally grayscale image uses 8 bit per pixel
# But grayscale image can use much bit per pixel like 16 bit or anything for specific domains like medical image
# img 2018-05-20 14-13-19.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 14-13-19.png"><xmp>

# =======================================================================
# color image
# =======================================================================

# To express color image, you should use basic colors to express various colors
# There are many kinds of basic color like 3 colors of light (rgb), 3 colors of color (cmy)

# Color image uses typically 24 bit (8 bit for R, 8 bit for G, 8 bit for R) per pixel, 
# which means you can use 16,777,216 colors

# Above kind of way is called true color image
# img 2018-05-20 14-21-02.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 14-21-02.png"><xmp>

# Even if true color image can express tons of colors, size of image becomes flaw (too big, one image can size up to 100mb)
# And 16777217 colors are kind of useless because human can disinguish them

# To resolve above issues, you can use mix of rgb with lookup table (additional information for rgb)
# In R channel, you can see light on blue area
# You can see light on yellow area from R channel and G channel, 
# whcih means you can generate yellow color if you mix red and green
# img 2018-05-20 14-26-57.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 14-26-57.png"><xmp>

# img 2018-05-20 14-28-49.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 14-28-49.png"><xmp>

# Value in pixel is index value of lookup table

# This way is called indexed color image

# jpeg can store true color image and grayscale image, not indexed color image
# bmp can store true color image and grayscale image, indexed color image
# gif can store indexed color image not true color image

# Input data for computer vision libraries should be true color image

# =======================================================================
# multi spectral image
# =======================================================================

# There are visible areas and invisible area from sun light
# Visible area is narrow
# img 2018-05-20 14-38-52.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 14-38-52.png"><xmp>

# You only deal with visible light when using computer vision

# But you can use other frequencies to see invisible things, which is called multi spectral image

# Satelite can't take picture of typhoon with visible light, and even can't take picture at night without light
# In this case, satelite can take picture of typhoon with infrared light
