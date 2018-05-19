// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// how to access data (pixel) from Mat representing image, how to bring color data
// 002_003.cpp
// https://www.youtube.com/watch?v=R35Oz97ofY4&index=13&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// =======================================================================
// Concepts
// =======================================================================

// =======================================================================
// Accessing to specific pixel data from image
// =======================================================================
// Suppose image (width is 200, height is 100)
// One pixel is generally denoted by value between 0 (black) to 255 (white), occupying 1byte (8bit)

// However, real buffer of image consists of 1d array, not 2d array
// For example, <1row><2row><3row>...<100row>, where length of each row is 200
// data[0] is 0 index pixel of <1row>
// Suppose you want to access to (x,y) pixel from image
data[y*width(200 in this case)+x]

// =======================================================================
// Accessing to specific color data from pixel data of colored image
// =======================================================================
// If image has color, pixel has 3 values, in case of rgb, requiring 3bytes
// Note that order is BGR than RGB

// Let's say you use buffer d for image
// If you want to bring b value from (x,y) pixel 
d[y*width(200 in this case)*3+x*3+0]
// g value
d[y*width(200 in this case)*3+x*3+1]
// r value
d[y*width(200 in this case)*3+x*3+2]
// You should use multiplication by 3 because you're using 3bytes than 1byte
