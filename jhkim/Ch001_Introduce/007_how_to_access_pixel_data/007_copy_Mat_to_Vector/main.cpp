// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/007_copy_Mat_to_Vector && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/007_copy_Mat_to_Vector/main.cpp \
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
  int r=3;
  int c=4;

  // ======================================================================
  // c Vf: Create vector instance, elements are float.
  vector<float> Vf;

  // ======================================================================
  // Initialize vector Vf by using push_back()
  int cnt=0;
  for(int i=0;i<c;++i)
  {
    for(int j=0;j<r;++j)
    {
      Vf.push_back(cnt++);
    }
  }
  
  // ======================================================================
  // for(vector<float>::iterator it=Vf.begin();it!=Vf.end();++it)
	//   cout<<' '<<*it;
  //  0 1 2 3 4 5 6 7 8 9 10 11

  // ======================================================================
  // c M : (3,4) array, element is CV_32FC1
  Mat M=Mat(r,c,CV_32FC1);

  // ======================================================================
  // You copy vector to Mat
  memcpy(M.data,Vf.data(),Vf.size()*sizeof(float));

  // ======================================================================
  // std::cout<<"M: "<<M<<std::endl;
  // [0, 1, 2, 3;
  //  4, 5, 6, 7;
  //  8, 9, 10, 11]

  // ======================================================================
  vector<float> Vf2;

  // ======================================================================
  // You copy mat (M) into vector (Vf2)
  Vf2.assign((float*)M.datastart,(float*)M.dataend);
  
  // ======================================================================
  // You can see result
  cnt=0;
  for(int i=0;i<c;++i)
  {
    for(int j=0;j<r;++j)
    {
      printf("%lf ",Vf2[cnt++]);
    }
    printf("\n");
  }

  return 0;
}

// // ======================================================================
// // Image buffer(point) copy to Mat
// // when you want to copy "unsigned char * pData" image buffer to Mat class in OpenCV.
// // ======================================================================
// // You first should sync size, data type between image buffer and Mat
// Mat InImg(height, width, CV_8UC1);
// // InImg.data : target
// // pData : source
// memcpy(InImg.data, pData, sizeof(unsigned char)*width*height);

