# This text is note I wrote from following lecture :
# http://www.kocw.net/home/search/kemView.do?kemId=434142&ar=relateCourse

# point operation-histogram(stretching,shrinking,sliding,equalization)
# 005_002.py

# =======================================================================
# histogram
# =======================================================================

# You can use 1d array for creating histogram
# Histogram is datum which gives number of pixels related to given value in image
# in case of 8 bit gray scale image,

# Table (1d array) is not good for understanding at one glance
# bin : brightness level
# probability : count/entire count
# So, you can use bar chart
# 2018-05-20 18-36-44.png

# in case of 8 bit grayscale image, bin has range from 0 to 255, 256 units
# in case of 4 bit grayscale image, bin has range from 0 to 15, 16 units

# 8 bit for R, 8 bit for B, 8 bit for G, entire size of pixel is 24 bit is true color image

# When true color image is input, how to find histogram on it?
# Since true color image uses 24 bits, one pixel can express almost 16000000 colors 

# way 1 : if image is 100*100, number of pixel is 10000
# Since 16000000 is too greater than 10000, histograms will show sparse bars, so this way is not useful
# way 2 : Let's try to find each histogram for each color, then you will have 3 histograms, but this ways is not that useful
# way 3 : You perform color quantization 
# (step of extracting representive colors to convert true color image to index color image) to reduce size of image 

# =======================================================================
# subcategories of histogram
# =======================================================================

# 1. You don't change shape of histogram, but you change range, which is called histogram scaling (histogram stretching)
# 1. histogram scaling (histogram shrinking)
# 1. You don't change shape and range of histogram, but you change location, which is called histogram sliding
# 1. You change shape, which is called histogram equalization
# img 2018-05-21 05-41-58.png

# =======================================================================
# mapping function for histogram scaling
# =======================================================================

# Suppose input histogram's range is 50 to 100
# You want to stretch range to 10 to 210
# How do you create mapping function for this?
# 50 should be mapped to 10, 100 should be mapped to 210, 75 should be mapped to 110
# (100-50):(x-50)=(210-10):(y-10)
# $$$y=\frac{(210-10)}{(100-50)}(x-50)+10$$$
# $$$generalization : f(x,y)=\frac {(S_{max}-S_{min})} {(I_{max}-I_{min})} (f(x,y)-I_{min})+S_{min}$$$
# $$$S_{max}$$$ : maximum gray level value possible
# $$$S_{min}$$$ : minimum gray level value possible
# $$$I_{max}$$$ : largest gray level value in input image I(x,y)
# $$$I_{min}$$$ : smallest gray level value in input image I(x,y)

# img 2018-05-21 05-56-32.png

# =======================================================================
# histogram shrinking
# =======================================================================
# img 2018-05-21 05-57-18.png

# =======================================================================
# histogram sliding
# =======================================================================

# brightness low <- -> brightness high
# mapping function O(x,y)=I(x,y)+offset
# offset is amount to slide histogram (left or right)

# img 2018-05-21 06-00-10.png

# =======================================================================
# equalization to find maximal contrast
# =======================================================================

# high contrast vs good contrast
# high contrast : broad range
# good contrast : broad range + good shape (equal values on each bin)

# img 2018-05-21 06-03-24.png

# mapping function is CDF : cumulative distribution function
# img 2018-05-21 06-05-16.png

# =======================================================================
#       Deriving algorithm
# =======================================================================    

# I(l) : input histogram
# O(l) : output histogram
# $$$0\leq l < L$$$

# Since entire number of pixels is same between input histogram and output histogram, you can write :
# $$$\sum\limits_{l=0}^{L-1}I(l)=\sum\limits_{l=0}^{L-1}O(l)$$$

# You arbitraily choose level p from input histogram,
# then, you can guess there will be level q corresponded to p from output histogram
# $$$\sum\limits_{l=0}^{p}I(l)=\sum\limits_{l=0}^{q}O(l)$$$

# You can denote output histogram O(l) as follow:
# $$$O(l)=\frac{T}{N_{max}-N_{min}}$$$
# T : number of entire pixel (ie, 100*100 image has 10000 pixels)
# $$$N_{max}$$$ : maximal brightness of image
# $$$N_{min}$$$ : minimal brightness of image

# You can write by using above relation :
# $$$\sum\limits_{l=0}^{q}O(l)=q\times\frac{T}{N_{max}-N_{min}} = \sum\limits_{l=0}^{p}I(l)$$$

# You want to find level q
# You write above formular in respect to q :
# $$$E(q,I)=q=\frac{N_{max}-N_{min}}{T}\sum\limits_{l=0}^{p}O(l)$$$

# step summary:
# 1. You calculate cumulative sum for each level from input histogram
# 1. You normalize cumulative sum by dividing cumulative sum by number of entire pixel
# 1. You multiply normalized value by maximal gray level value, then perform round up
# 1. You map each gray level value of input image into converted value
# img 2018-05-21 06-24-58.png
# img 2018-05-21 06-28-00.png
# img 2018-05-21 06-28-18.png

# =======================================================================
# histogram normalization vs equalization
# =======================================================================

# img 2018-05-21 06-29-26.png

# =======================================================================
# disadvantage of equalization
# =======================================================================

# background noise can be increased
# image quality in near constant region may be degraded
