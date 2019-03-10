// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_008_Linear_algebra_operations_Solver_Eigen_value_Vector_SVD/003_Use_SVD && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_008_Linear_algebra_operations_Solver_Eigen_value_Vector_SVD/003_Use_SVD/main.cpp \
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
  // =======================================================================
  // SVD (singular value decomposition)

  float f11[]={
    1,0.446,
    -0.56,
    0.446,
    1,
    -0.239,
    -0.56,
    0.239,1};

  Mat data(3,3,CV_32F,f11);

  // ======================================================================
  Mat w,u,v;

  // ======================================================================
  // SVDecomp() decomposes matrix "data" into 3 matrices (w,u,v)
  // with satisfying a relationship of A=u*w*v^{T}
  // Note that unique characteristic of matrix A will be inserted into u, w, v
  SVDecomp(data,w,u,v);

  // ======================================================================
  // std::cout<<"w: "<<w<<std::endl;
  // [1.7264543;
  //  1.0320926;
  //  0.3056384]

  // std::cout<<"u: "<<u<<std::endl;
  // [0.70055079, 0.046833798, 0.71206409;
  //  0.49161381, 0.69160181, -0.52915293;
  // -0.51724702, 0.72075903, 0.46147805]
  
  // std::cout<<"v: "<<v<<std::endl;
  // [0.70055079, 0.39412421, -0.59489053;
  // -0.046833828, 0.85723996, 0.51278269;
  //  0.71206409, -0.3313694, 0.61899853]

  return 0;
}
