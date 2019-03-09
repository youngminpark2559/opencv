// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_008_Linear_algebra_operations_Solver_Eigen_value_Vector_SVD/001_solve_function && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_008_Linear_algebra_operations_Solver_Eigen_value_Vector_SVD/001_solve_function/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
#include <iostream>
#include <cstring>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
  // c dm2: A
  double dm2[3][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9}};

  // c A: create A
  Mat A(3,3,CV_64FC1,dm2);

  // ======================================================================
  // c x: create x
  Mat x(3,1,CV_64FC1);

  // ======================================================================
  double vvb[]={14,32,52};
  // c b: create b
  Mat b(3,1,CV_64FC1,vvb);

  // ======================================================================
  // This solves Ax=b with respect to x
  // c DECOMP_SVD: option, DECOMP_SVD stands for decomposition SVD
  cv::solve(A,b,x,DECOMP_SVD);

  // ======================================================================
  std::cout<<"x: "<<x<<std::endl;
  // [1.611111111111109;
  //  2.111111111111111;
  //  2.611111111111113]

  // ======================================================================
  std::cout<<"A*x: "<<A*x<<std::endl;
  // [13.66666666666667;
  //  32.66666666666667;
  //  51.66666666666667]

  // ======================================================================
  // std::cout<<"b: "<<b<<std::endl;
  // [14;
  //  32;
  //  52]

  return 0;
}
