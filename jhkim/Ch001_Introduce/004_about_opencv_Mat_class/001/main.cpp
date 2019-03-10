// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/001_Introduce_004_about_opencv_Mat_class/001 && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/001_Introduce_004_about_opencv_Mat_class/001/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

#include<iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
  // Create (3,3) array.
  // Data type of each element in that array is 32 bits float.
  // Array is initialized by 0s.
  Mat mtx(3,3,CV_32F);
  // std::cout<<"mtx: "<<mtx<<std::endl;
  // [0, 0, 0;
  //  0, 0, 0;
  //  0, 0, 0]

  // ======================================================================
  // Create (10,1) array but 2 channel, that is, (10,2) array?
  // CV_64FC2: data type of element in array, 64 bits float.
  // C2: number of channels, 2 channels.
  Mat cmtx(10,1,CV_64FC2);
  // std::cout<<"cmtx: "<<cmtx<<std::endl;
  // [2.371515100037983e-322, 0;
  //  0, 0;
  //  4.799333386002941e-314, 0;
  //  0, 0;
  //  0, 0;
  //  0, 0;
  //  1.645905391646978e-316, 1.645908948919628e-316;
  //  5.928787750094959e-323, 1.976262583364986e-323;
  //  4.940656458412465e-324, 6.365987376848342e-314;
  //  2.121995792447469e-314, 0]

  // ======================================================================
  // Size(5,3): (5,3) array.
  // CV_8UC3: 8 bits, unsigned character.
  // C3: 3 channels.
  // CV_8UC3 is general form in an image processing task.
  Mat img(Size(5,3),CV_8UC3);
  // std::cout<<"img: "<<img<<std::endl;
  // [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
  //    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0;
  //    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0]

  // ======================================================================
  // c mtx2: create Mat instance.
  Mat mtx2;
  // (3,3) array, 32bit float.
  mtx2=Mat(3,3,CV_32F);

  Mat cmtx2;
  // (10,1) array, 32bit float, 2 channels.
  cmtx2=Mat(10,1,CV_64FC2);

  // ======================================================================
  // You can use dynamic allocation when using Mat class.
  Mat* mtx3=new Mat(3,3,CV_32F);

  // When processing with mtx3 is finished, 
  // you should delete mtx3 instance from memory.
  delete mtx3;

  // ======================================================================
  // setTo() is member function of Mat class.

  // You put 10s into all elements of mtx instance.
  mtx.setTo(10);

  // std::cout<<"mtx: "<<mtx<<std::endl;
  // [10, 10, 10;
  //  10, 10, 10;
  //  10, 10, 10]

  // ======================================================================
  cmtx2.setTo(11);
  // std::cout<<"cmtx2: "<<cmtx2<<std::endl;
  // [11, 11;
  //  11, 11;
  //  11, 11;
  //  11, 11;
  //  11, 11;
  //  11, 11;
  //  11, 11;
  //  11, 11;
  //  11, 11;
  //  11, 11]

  return 0;
}
