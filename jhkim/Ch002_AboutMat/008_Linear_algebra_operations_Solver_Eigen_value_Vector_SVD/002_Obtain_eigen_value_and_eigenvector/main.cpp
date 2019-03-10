// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_008_Linear_algebra_operations_Solver_Eigen_value_Vector_SVD/002_Obtain_eigen_value_and_eigenvector && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_008_Linear_algebra_operations_Solver_Eigen_value_Vector_SVD/002_Obtain_eigen_value_and_eigenvector/main.cpp \
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
  // Eigen analysis, Eigenvector, Eigenvalue (A*V=v*V)

  // c f11: source for matrix data
  float f11[]={1,0.446,-0.56,0.446,1,-0.239,-0.56,0.239,1};

  // c data: (3,3) matrix
  Mat data(3,3,CV_32F,f11);

  // ======================================================================
  Mat value,vector;

  // ======================================================================
  // c data: source matrix
  // c value: calculated eigenvalue
  // c vector: calculated eigenvector
  eigen(data,value,vector);

  // ======================================================================
  // std::cout<<"eigenvalues: "<<value<<std::endl;
  // [1.8433276;
  //  0.76869339;
  //  0.387979]

  // std::cout<<"eigenvectors: "<<vector<<std::endl;
  // [-0.64669836, -0.50420839, 0.57232428;
  //  -0.094041198, 0.79732966, 0.59617251;
  //  0.7569263, -0.33172169, 0.56304806]

  // ======================================================================
  // You prove whether the result from eigen() is correct 
  // by manulally calculating formular of (A*V=v*V)
  // std::cout<<"A*V, in other words data*vector: " <<data*vector<<std::endl;
  // [-1.1125195, 0.037164792, 0.52291036;
  //  -0.56337404, 0.65173423, 0.71686065;
  //  1.0966015, 0.14119682, 0.3850317]

  // ======================================================================
  // std::cout<<"v*V: " <<data*vector<<std::endl;
  // [-1.1125195, 0.037164792, 0.52291036;
  //  -0.56337404, 0.65173423, 0.71686065;
  //   1.0966015, 0.14119682, 0.3850317]

  // c ValueEye: (3,3) identity matrix
  Mat ValueEye=Mat::eye(3,3,CV_32F);

  // ======================================================================
  // You insert each eigenvalue into ValueEye
  ValueEye.at<float>(0,0)=value.at<float>(0,0);
  ValueEye.at<float>(0,0)=value.at<float>(0,0);
  ValueEye.at<float>(0,0)=value.at<float>(0,0);

  // ======================================================================
  // std::cout<<"vector*ValueEye: "<<vector*ValueEye<<std::endl;
  // [-1.1920769, -0.50420839, 0.57232428;
  //  -0.17334874, 0.79732966, 0.59617251;
  //   1.3952632, -0.33172169, 0.56304806]

  return 0;
}
