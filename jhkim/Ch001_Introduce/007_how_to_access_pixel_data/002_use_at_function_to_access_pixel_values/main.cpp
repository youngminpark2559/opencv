// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/002 && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/002/main.cpp \
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
  // Let's use at() to access to the pixel.
  // You access "partial rows"
  for(int i=img.rows/10*3;i<img.rows/10*4;++i)
  {
    // You access "all columns"
    for(int j=0;j<img.cols;++j)
    {
      // You get pixel values from "img"
      // cv::Vec3b: data type you're using.
      // 0,1,2: stands for BGR values.
      unsigned char b=img.at<cv::Vec3b>(i,j)[0];
      unsigned char g=img.at<cv::Vec3b>(i,j)[1];
      unsigned char r=img.at<cv::Vec3b>(i,j)[2];

      // ======================================================================
      // Let's invert the image by subtracting 255 from b,g,r values
      img.at<cv::Vec3b>(i,j)[0]=(255-b);
      img.at<cv::Vec3b>(i,j)[1]=(255-g);
      img.at<cv::Vec3b>(i,j)[2]=(255-r);
    }
  }

  imshow("img",img);
  waitKey(0);

  return 0;
}
