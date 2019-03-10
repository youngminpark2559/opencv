// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/006_copy_Vector_to_Mat_Copy_Mat_to_vector && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/006_copy_Vector_to_Mat_Copy_Mat_to_vector/main.cpp \
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

  return 0;
}
