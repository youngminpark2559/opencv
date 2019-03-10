// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_002_Mat_Basic_functions_copy_copyTo_clone_range_region_copy/005_use_copyTo_function && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_002_Mat_Basic_functions_copy_copyTo_clone_range_region_copy/005_use_copyTo_function/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
  Mat img=imread("./../../../universe.jpg");

  // ======================================================================
  // You invert "img" and assign the result into "img" variable
  bitwise_not(img,img);

  // ======================================================================
  imshow("img",img);

  // ======================================================================
  Mat img2=img.clone();

  // ======================================================================
  Rect r(img.cols/4,img.rows/4,img.cols/4*2,img.rows/4*2);

  // =======================================================================
  Mat cimg;

  // ======================================================================
  // c img : original image which will be copied
  // c cimg : place where copied image will be assigned to
  img.copyTo(cimg);
  imshow("cimg",cimg);

  // =======================================================================
  // Using copyTo() member method (deep copy) with Rect type

  Mat cimg2;
  // You deeply copy only r area of original image (img) into cimg2
  img(r).copyTo(cimg2);
  imshow("cimg2",cimg2);

  // =======================================================================
  // Use copyTo() to copy image onto 2-times-expanded-empty-window

  // You create 2 times width column empty area
  Mat cimg3(Size(img.cols*2,img.rows),img.type());
  
  // You initialize color of empty window to white (255)
  cimg3.setTo(255);

  // You fully copy img, paste onto all areas of row Range::all(),
  // paste onto Range(0,img.cols)
  img.copyTo(cimg3(Range::all(),Range(0,img.cols)));

  // You fully copy img and paste it onto right area
  img2.copyTo(cimg3(Range::all(),Range(img2.cols,img2.cols*2)));
  imshow("cimg3",cimg3);

  // =======================================================================
  // Using variable initilization syntax (reference way)

  // You bring img
  // Only r area of img
  Mat roi(img,r);
  imshow("roi",roi);
  waitKey(0);
}
