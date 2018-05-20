# This text is note I wrote from following lecture :
# http://www.kocw.net/home/search/kemView.do?kemId=434142&ar=relateCourse

# point operation-arithmetic operation, grayscale transformation
# 005_001.py

# =======================================================================
# Image processing
# =======================================================================
# 1. point operation is to change one pixel with new value to create new image
# 1. pixel group processing is to change pixels around pixel

# =======================================================================
# point operation
# =======================================================================

# 1. in-place transformation:
# I(x,y)==O(x,y)
# img 2018-05-20 17-24-47.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 17-24-47.png"><xmp>

# =======================================================================
# overview techniques
# =======================================================================

# 1. arithmetic operation
# 1. grayscale transformation
# 1. histogram modification

# Above 3 techniques have same goal (manipulating image's contrast, manipulating image's brightness)

# high contrast, low contrast (brightness low), low contrast (brightness high)

# You can see image's information with histogram which represents distribution brightness
# Left area of histogram corresponds to black
# Right area of histogram corresponds to white

# img 2018-05-20 17-30-41.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 17-30-41.png"><xmp>

# =======================================================================
# scalar arithmetic operation (operation on one constant value from one pixel)
# image arithmetic operation
# =======================================================================

# $$$O(x,y)=k\times I(x,y)+l$$$
# I(x,y) : input image
# O(x,y) : output image
# l : level
# k : gain

# When you process operation, result can exceeds given range, for example, 0 to 255
# You can process that issue with clipping process
# if O(x,y)>255, O(x,y)=255
# if O(x,y)<0, O(x,y)=0

# You will see 2 cases applied by arithmetic operation on pixel
# case1 : I=50,k=1
# case2 : I=-50,k1
# Wide distribution in histogram means high contrast

# img 2018-05-20 17-37-43.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 17-37-43.png"><xmp>

# =======================================================================
# image arithmetic operation
# =======================================================================

# You will use multiple images to perform operation

# Let's generate 5 types of noise on raw image without noise
# 1st image is removed from noise with average value by 2 noised images
# 2nd image is removed from noise with average value by 5 noised images
# img 2018-05-20 17-43-00.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 17-43-00.png"><xmp>

# =======================================================================
# difference on images
# =======================================================================

# 1. get diffence
# 2. apply thresholding
# img 2018-05-20 17-44-59.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 17-44-59.png"><xmp>
# img 2018-05-20 17-45-37.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 17-45-37.png"><xmp>

# =======================================================================
# grayscale transformation operation
# =======================================================================
# In respect to input image I(x,y), you define mapping function M,
# based on mapping function M, you generate new result image O(x,y)

# Mapping function can be simply 1 order fucntion or higher order functions 
# Generally, 1 or 2 order functions are used much

# example :
# Suppose image has gray level,
# and you want to convert gray level from (10,50) to (10,250) to increase contrast (with broader gray level)

# Mapping function M : no change, change, no change
# $$$M[I(x,y)]=\left\{\begin{matrix} I(x,y)&0\leq I(x,y)<10 \\  6[I(x,y)]-50&10\leq I(x,y)\leq 50 \\  I(x,y)&50\leq I(x,y)\leq 255 \\ \end{matrix}\right$$$
# img 2018-05-20 18-03-54.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 18-03-54.png"><xmp>

# brightness scaling by multiplication
    # decrease contrast
    # img 2018-05-20 18-08-10.png
    # </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 18-08-10.png"><xmp>

    # increase contrast
    # img 2018-05-20 18-09-38.png
    # </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 18-09-38.png"><xmp>

    # increase contrast at specific range
    # img 2018-05-20 18-11-21.png
    # </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 18-11-21.png"><xmp>

# gray level thresholding :
# result is binary image
# img 2018-05-20 18-12-28.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 18-12-28.png"><xmp>

# gray level negative (or brightness inversion) :
# dim to bright, bright to dim
# img 2018-05-20 18-13-55.png
# </xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 18-13-55.png"><xmp>
