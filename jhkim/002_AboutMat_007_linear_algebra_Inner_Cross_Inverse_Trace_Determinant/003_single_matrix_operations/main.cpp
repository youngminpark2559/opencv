// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_007_linear_algebra_Inner_Cross_Inverse_Trace_Determinant/003_single_matrix_operations && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_007_linear_algebra_Inner_Cross_Inverse_Trace_Determinant/003_single_matrix_operations/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

// ======================================================================
int main(int,char)
{

  Mat Ma=Mat::eye(3,3,CV_64FC1);
  // std::cout<<"Ma: "<<Ma<<std::endl;
  // [1, 0, 0;
  //  0, 1, 0;
  //  0, 0, 1]

  // ======================================================================
  double dm[3][3]={{1,2,3},{4,5,6},{7,8,9}};

  // ======================================================================
  Mat Mb=Mat(3,3,CV_64F,dm);
  // std::cout<<"Mb: "<<Mb<<std::endl;
  // [1, 2, 3;
  //  4, 5, 6;
  //  7, 8, 9]

  // ======================================================================
  Mat Mc;

  // ======================================================================
  cv::add(Ma,Mb,Mc); // Ma+Mb -> Mc
  // std::cout<<"Ma+Mb: "<<Ma+Mb<<std::endl;
  // [2, 2, 3;
  //  4, 6, 6;
  //  7, 8, 10]

  // std::cout<<"Mc: "<<Mc<<std::endl;
  // [2, 2, 3;
  //  4, 6, 6;
  //  7, 8, 10]

  // ======================================================================
  cv::subtract(Ma,Mb,Mc); // Ma-Mb -> Mc
  // std::cout<<"Ma-Mb: "<<Ma-Mb<<std::endl;
  // std::cout<<"Mc: "<<Mc<<std::endl;

  // ======================================================================
  Mc=Ma*Mb; //Ma*Mb;
  // std::cout<<"Mc: "<<Mc<<std::endl;
  // [1, 2, 3;
  //  4, 5, 6;
  //  7, 8, 9]

  // ======================================================================
  //Elementwise matrix operations:
  // .* stands for elementwise operation
  cv::multiply(Ma,Mb,Mc); // Ma.*Mb -> Mc
  // std::cout<<"Mc: "<<Mc<<std::endl;

  // ======================================================================
  Mc=Ma.mul(Mb);
  // std::cout<<"Mc: "<<Mc<<std::endl;

  // ======================================================================
  cv::divide(Ma,Mb,Mc); // Ma./Mb -> Mc
  // std::cout<<"Mc: "<<Mc<<std::endl;

  // ======================================================================
  Mc=Ma+10; // Ma+10=Mc
  // std::cout<<"Mc: "<<Mc<<std::endl;

  // =======================================================================
  // Vector product
  // 1. inner product: dot(), 
  // you can calculate the angle between 2 vectors
  // 2. outer product: cross(), 
  // you can find a vector which is perpendular against both vectors

  // ======================================================================
  double va[]={1,2,3};
  double vb[]={0,0,1};
  double vc[3];

  // ======================================================================
  Mat Va(3,1,CV_64FC1,va);
  Mat Vb(3,1,CV_64FC1,vb);
  Mat Vc(3,1,CV_64FC1,vc);

  // ======================================================================
  // Inner product
  double res=Va.dot(Vb);
  // std::cout<<"res: "<<res<<std::endl;
  // res: 3

  // ======================================================================
  // Outer product
  Vc=Va.cross(Vb);
  // std::cout<<"Vc: "<<Vc<<std::endl;
  // [2;
  // -1;
  //  0]

  // =======================================================================
  // 003_single_matrix_operations

  // You transpose Mb
  Mc=Mb.t();
  // std::cout<<"Mc: "<<Mc<<std::endl;
  // [1, 4, 7;
  //  2, 5, 8;
  //  3, 6, 9]

  // ======================================================================
  // You have to use Scalar type to obtain result from trace()
  cv::Scalar t=trace(Ma);

  // To print result, you have to use .val[0]
  // std::cout<<"t.val[0]: "<<t.val[0]<<std::endl;
  // t.val[0]: 3

  // ======================================================================
  double d=determinant(Ma);
  // std::cout<<"d: "<<d<<std::endl;
  // d: 1

  // ======================================================================
  Mc=Ma.inv();
  // std::cout<<"Mc: "<<Mc<<std::endl;
  // [1, 0, 0;
  //  0, 1, 0;
  //  0, 0, 1]

  // ======================================================================
  invert(Ma,Mc);
  // std::cout<<"Mc: "<<Mc<<std::endl;
  // [1, 0, 0;
  //  0, 1, 0;
  //  0, 0, 1]

  // ======================================================================
  return 0;
}
