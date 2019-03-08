// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/002_AboutMat_001_Load_and_show_Image_Video/001_Read_image && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/002_AboutMat_001_Load_and_show_Image_Video/001_Read_image/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

#include "opencv2/opencv.hpp"
#include <iostream>
#include <cstring>
using namespace cv;
using namespace std;
 
int main()
{
  // c img: read image, and save that image into img.
  Mat img=imread("universe.jpg");

  // You can read an image in grayscale
  // Mat img=imread("universe.jpg",0);
  
  // ======================================================================
  // Create named window
  // 0: you can resize image window
  // 1: you can't rezie window, and image is shown in original size
  // You actually can omit namedWindow to display image
  // But if you omit namedWindow, you can't use options (like 0 and 1)
  namedWindow("img",1);

  // ======================================================================
  imshow("img",img);

  // ======================================================================
  waitKey(0);

  return 0;
}
