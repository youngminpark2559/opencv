// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/004_use_data_to_access_pixel_values && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/004_use_data_to_access_pixel_values/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
// OpenCV Pixel Access, at, ptr, data, iteration (example)
// http://study.marearts.com/2014/04/opencv-study-mat-point-access-method.html

// ======================================================================
#include <iostream>
#include <cstring>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
 
int main()
{
  // ======================================================================
  // c img : Mat type instance, ss.jpg file is assigned to img.
  Mat img=imread("universe.jpg");
  namedWindow("img",0);

  // ======================================================================
  // Get pixel values via data approach
  // You access all rows from the image.
  for(int i=img.rows/10*8;i<img.rows/10*9;i++)
  {
    // You access partial columns from the image.
    for(int j=0;j<img.cols;j++)
    {
      // Create variables which will store pixel value
      unsigned char r,g,b;

      // ======================================================================
      // You get pixel value via indices which should be manually calculated by yourself.
      b=img.data[i*img.step+j*img.elemSize()+0];
      g=img.data[i*img.step+j*img.elemSize()+1];
      r=img.data[i*img.step+j*img.elemSize()+2];

      // ======================================================================
      // You put new pixel value into same pixel positions.
      // (unsigned char): stands for type casting.
      img.data[i*img.step+j*img.elemSize()+0]=(unsigned char)(255-b);
      img.data[i*img.step+j*img.elemSize()+1]=(unsigned char)(255-g);
      img.data[i*img.step+j*img.elemSize()+2]=(unsigned char)(255-r);
    }
  }

  imshow("img",img);
  waitKey(0);

  return 0;
}
