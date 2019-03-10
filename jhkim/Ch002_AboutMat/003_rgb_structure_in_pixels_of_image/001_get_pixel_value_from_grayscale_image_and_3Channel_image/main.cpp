// 2D image is stored as 1D array in memory

// ======================================================================
// Suppose (100,200) image (100 is width length, 200 is height length)

// Above image is expressed as 100*200 1D array 

// If you want to get (x,y) pixel, you can use following notation
// image[y*width+x]

// ======================================================================
// Suppose (100,200,3) color image 
// (100 is width length, 200 is height length, 3 is RGB channel)

// Above image is expressed as 100*200*3 1D array 

// OpenCV expresses pixel in BGR

// If you want to get RGB values in (x,y) pixel, you can use following notation
// image[y*width*3+x*3]

// If you want to get B values in (x,y) pixel, you can use following notation
// image[y*width*3+x*3+0]

// If you want to get G values in (x,y) pixel, you can use following notation
// image[y*width*3+x*3+1]

// If you want to get R values in (x,y) pixel, you can use following notation
// image[y*width*3+x*3+2]

// ======================================================================