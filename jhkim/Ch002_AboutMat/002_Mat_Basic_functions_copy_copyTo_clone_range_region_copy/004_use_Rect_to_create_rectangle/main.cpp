// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_002_Mat_Basic_functions_copy_copyTo_clone_range_region_copy/004_use_Rect_to_create_rectangle && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_002_Mat_Basic_functions_copy_copyTo_clone_range_region_copy/004_use_Rect_to_create_rectangle/main.cpp \
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
  // img.cols/4,img.rows/4: stands for the starting location of a rectangle
  // img.cols/4*2,img.rows/4*2: stands for the length of width and height
  // c r: create Rect instance
  Rect r(img.cols/4,img.rows/4,img.cols/4*2,img.rows/4*2);
  std::cout<<"r: "<<r<<std::endl;

  // ======================================================================
  // You fullly copy "original image (img)" 
  // by the partial size which is determined by r,
  // Then, you assign the result into img5
  Mat img5=img(r).clone();
  imshow("img5",img5);
  waitKey(0);

  // // =======================================================================
  // //      Using copyTo() member method (deep copy)
  // // =======================================================================

  // Mat cimg;
  // // c img : original image to be copied
  // // c cimg : place where copied image will be assigned to
  // img.copyTo(cimg);
  // imshow("cimg",cimg);

  // // =======================================================================
  // //      Using copyTo() member method (deep copy) with Rect type
  // // =======================================================================

  // Mat cimg2;
  // // You deeply copy only r area of original image (img) into cimg2
  // img(r).copyTo(cimg2);
  // imshow("cimg2",cimg2);

  // // =======================================================================
  // //      Using copyTo() onto 2 times expanded empty window
  // // =======================================================================

  // // You create 2 times width column empty area
  // Mat cimg3(Size(img.cols*2,img.rows),img.type());
  // // You initialize color of empty window to white (255)
  // cimg3.setTo(255);

  // // You fully copy img, paste onto all area of row Range::all(),
  // // paste onto Range(0,img.cols)
  // img.copyTo(cimg3(Range::all(),Range(0,img.cols)));
  // // You fully copy img and paste it onto right area
  // img2.copyTo(cimg3(Range::all(),Range(img2.cols,img2.cols*2)));

  // // =======================================================================
  // //      Using variable initilization syntax (reference way)
  // // =======================================================================

  // // Only r area of img
  // // You bring img
  // Mat roi(img,r);
  // imshow("roi",roi)
}
