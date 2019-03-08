// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/003_use_ptr_to_access_pixel_values && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/003_use_ptr_to_access_pixel_values/main.cpp \
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
  // You'll access "partial rows" in the image.
  for(int i=img.rows/10*6;i<img.rows/10*7;i++)
  {   
    // cv::Vec3b: data type which you're using in image array.
    // c ptr: extracted pixel value
    cv::Vec3b *ptr=img.ptr<cv::Vec3b>(i);
    
    // ======================================================================
    // Get pixels
    // You'll access "entire columns" in the image.
    for (int j=0;j<img.cols;j++)
    {
      cv::Vec3b bgr=ptr[j];
      // You can use above bgr to access to the pixel value.
      unsigned char b=(bgr[0]);
      // Or you can use ptr pointer to access to the pixel value.
      // j: stands for column,
      // 1: stands for channel
      unsigned char g=(ptr[j][1]); 
      unsigned char r=(bgr[2]);

      // ======================================================================
      // Invert partial area from the image
      ptr[j]=cv::Vec3b(255-b,255-g,255-r);
    }
  }  

  imshow("img",img);
  waitKey(0);

  return 0;
}
