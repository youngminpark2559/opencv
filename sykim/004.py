# This text is note I wrote from following lecture :
# http://www.kocw.net/home/search/kemView.do?kemId=434142&ar=relateCourse

# overview computer vision and image processing
# 004.py

# =======================================================================
# computer vision
# =======================================================================

# Result of processing is used by computer, or you process image for computer to use result

# Computer takes in image and finds good information (description) from passed image
# To do this, processing various task on image is required
# but processing is automatically proceeded by computer

# That is, computer automatically takes in input based on algorithm, processes images, uses result of process

# =======================================================================
# fields of computer vision applied
# =======================================================================

# 1. factory automation system
# quality control, inspection

# 1. automatic identification (biometrics system)
# DNA analysis, fingerprints identification, retinal identification

# 1. medical diagnostic system

# 1 intelligent transport system
# autonomous car

# =======================================================================
# pattern recognition
# =======================================================================

# Computer vision is performed by mainly pattern recognition
# Pattern recognition : 
# when you're given by input object (pattern), you use given algorithm
# to classify object (pattern) into category or class

# =======================================================================
# step of pattern recognition
# =======================================================================

# low quality input image
#     image enhancement
# high quality input image
#     image segmentation (between object and background)
# segmented object image
#     feature extraction (color,shape,texture,...)
# feature
#     pattern classification
# banana

# img 2018-05-20 15-25-06.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 15-25-06.png"><xmp>

# =======================================================================
# feature
# =======================================================================

# when you extract features from image, then, you can express image as dots on xy space
# x : color
# y : shape
# Graph shows set of dots representing banana and apple

# length and round can be denoted by "thinness ratio"
# thinness ratio $$$T=4\pi(\frac{A}{P^{2}})$$$
# A : area
# P : length of contour
# In case of circle, $$$T=1=4\pi(\frac{\pi r^{2}}{(2\pi^{2})^{2}})$$$

# T is between 0 and 1
# ellipse becomes towards 0
# $$$T_{apple}>T_{banana}$$$

# img 2018-05-20 15-39-53.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 15-39-53.png"><xmp>

# =======================================================================
# image processing
# =======================================================================

# Result of processing is used by human
# And step of processing is also intervened by human

# Fields of image processing
# 1. image restoration
# When you know reason of distortion, when you create model about distortion
# model about distortion can be made by math, 
# then you can apply that mathematical model in reverse to remove distortion
# img 2018-05-20 15-44-34.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 15-44-34.png"><xmp>

# 1. image enhancement
# When you don't know reason of distortion, 
# when you can't create mathematical model about distortion
# img 2018-05-20 15-46-12.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 15-46-12.png"><xmp>

# 1. image compression
# img 2018-05-20 15-47-00.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 15-47-00.png"><xmp>

# blocking detect
