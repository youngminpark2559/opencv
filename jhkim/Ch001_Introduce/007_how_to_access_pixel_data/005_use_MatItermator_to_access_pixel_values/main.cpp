// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/005_use_MatItermator_to_access_pixel_values && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/005_use_MatItermator_to_access_pixel_values/main.cpp \
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
  // c itd: create MatIterator instance 
  // with specifying begin and end of MatIterator.
  cv::MatIterator_<cv::Vec3b> itd=img.begin<cv::Vec3b>(),itd_end=img.end<cv::Vec3b>();

  // ======================================================================
  // Get all pixel values of the image.
  for(int i=0;itd!=itd_end;++itd,++i)
  {
    cv::Vec3b bgr=(*itd);
    (*itd)[0]=255-bgr[0];
    (*itd)[1]=255-bgr[1];
    (*itd)[2]=255-bgr[2];
  }

  imshow("img",img);
  waitKey(0);

  return 0;
}
