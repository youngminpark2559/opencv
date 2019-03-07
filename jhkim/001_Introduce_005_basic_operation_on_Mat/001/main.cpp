// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/001_Introduce_005_basic_operation_on_Mat/001 && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/001_Introduce_005_basic_operation_on_Mat/001/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main(int,char)
{   
  // c m: (3,3) 2D array.
  // Element of array is 64 bits float.
  // You initialize array by 1s.
  Mat m=Mat::ones(3,3,CV_64F);
  // std::cout<<"m: "<<m<<std::endl;
  // [1, 1, 1;
  //  1, 1, 1;
  //  1, 1, 1]

  // ======================================================================
  // You multipy 3 by m
  m=m*3;
  // std::cout<<"m: "<<m<<std::endl;
  // [3, 3, 3;
  //  3, 3, 3;
  //  3, 3, 3]

  // ======================================================================
  Mat m_z=Mat::zeros(3,3,CV_64F);
  // std::cout<<"m_z: "<<m_z<<std::endl;
  // [0, 0, 0;
  //  0, 0, 0;
  //  0, 0, 0]

  m_z=m_z*3;
  // std::cout<<"m_z: "<<m_z<<std::endl;
  // [0, 0, 0;
  //  0, 0, 0;
  //  0, 0, 0]
 
  // ======================================================================
  // c dm: (3,3) 2D array, element is float
  double dm[3][3]={{1,2,1},{0,1,1},{1,0,0}};

  // You initialize m2 by dm
  Mat m2=Mat(3,3,CV_64F,dm);
  // std::cout<<"m2: "<<m2<<std::endl;
  // [1, 2, 1;
  //  0, 1, 1;
  //  1, 0, 0]

  // =======================================================================
  // Arithmetics on mat objects

  // std::cout<<"m+m2: "<<m+m2<<std::endl;
  // [4, 5, 4;
  //  3, 4, 4;
  //  4, 3, 3]

  // std::cout<<"m-m2: "<<m-m2<<std::endl;
  // [2, 1, 2;
  //  3, 2, 2;
  //  2, 3, 3]

  // ======================================================================
  // Matrix multiplication (dot product)
  // std::cout<<"m*m2: "<<m*m2<<std::endl;
  // [6, 9, 6;
  //  6, 9, 6;
  //  6, 9, 6]

  // Element-wise multiplication
  // std::cout<<"m.mul(m2): "<<m.mul(m2)<<std::endl;
  // [3, 6, 3;
  //  0, 3, 3;
  //  3, 0, 0]

  // ======================================================================
  // std::cout<<"m/m2: "<<m/m2<<std::endl;
  // [3, 1.5, 3;
  //  inf, 3, 3;
  //  3, inf, 0]

  // =======================================================================
  // inverse matrix of m2
  // std::cout<<"m2.inv(): "<<m2.inv()<<std::endl;
  // [0, 0, 1;
  // 1, -1, -1;
  // -1, 2, 1]

  // =======================================================================
  // transpose matrix of m2
  // std::cout<<"m2.t(): "<<m2.t()<<std::endl;
  // [1, 0, 1;
  //  2, 1, 0;
  //  1, 1, 0]

  // =======================================================================
  // reference affects
  m2=m+m2;
  // std::cout<<"m2: "<<m2<<std::endl;
  // [4, 5, 4;
  //  3, 4, 4;
  //  4, 3, 3]

  // ======================================================================
  // This prints dm array
  // for (int i=0;i<3;++i)
  // {
  //   for (int j=0;j<3;++j)
  //     std::cout<<dm[i][j]<<" ";
  //   cout<<endl;
  // }
  // 4 5 4 
  // 3 4 4 
  // 4 3 3 

  // ======================================================================
  // This changes a value of array dm
  dm[2][2]=1000;

  // You can see changed value in m2
  // std::cout<<"m2: "<<m2<<std::endl;
  // [4, 5, 4;
  //  3, 4, 4;
  //  4, 3, 1000]

  return 0;
}