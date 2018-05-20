# step of digitalizing analog signal
# 001.py

# =======================================================================
# Overview of digitalization
# =======================================================================

# Step to convert analog image into digital image:
# sampling -> quantizing -> coding

# =======================================================================
# Sampling
# =======================================================================

# Object you're seeing is 3 dimension
# But digital image has 2 dimension
# This requires kind of projection to project 3d object into 2d image

# =======================================================================
# Quantization
# =======================================================================

# How many steps will you use to divide level of brightness between black and white
# High quantization shows more natural gradation
# img 2018-05-20 12-49-00.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20%2012-49-00.png"><xmp>

# 2 level : one pixel can have white or black
# 4 level : one pixel can have white, very white, black, very black
# 16 level, 256 level (natural, one pixel uses 8 bit)
# img 2018-05-20 12-51-56.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 12-51-56.png"><xmp>

# =======================================================================
# Coding
# =======================================================================

# Pixel actually has no shape
# But we conviniently express pixel as rectangle

# To store raw pixel data requires huge memory size
# So you perform step of compress, which is called coding
# img 2018-05-20 12-55-27.png
</xmp><img src="https://raw.githubusercontent.com/youngmtool/opencv/master/sykim/pic/2018-05-20 12-55-27.png"><xmp>
