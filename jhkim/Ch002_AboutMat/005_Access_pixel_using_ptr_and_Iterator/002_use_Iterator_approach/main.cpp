// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_005_Access_pixel_using_ptr_and_Iterator/002_use_Iterator_approach && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_005_Access_pixel_using_ptr_and_Iterator/002_use_Iterator_approach/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

// ======================================================================
int main(int,char)
{   
  // Create named window    
  namedWindow("img",1);

  // ======================================================================
  Mat img=imread("./../../../universe.jpg");
  imshow("img",img);

  // =======================================================================
  // Invert image using ptr approach

  // c itd: create MatIterator_ instance
  // Data type of itd is Vec3b
  // You insert begin and end into itd
  cv::MatIterator_<cv::Vec3b> itd=img.begin<cv::Vec3b>(),itd_end=img.end<cv::Vec3b>();

  // ======================================================================

  for(int i=0;itd!=itd_end;++itd,++i)
  {
    // You assign things which itd points into bgr
    cv::Vec3b bgr=(*itd);

    // ======================================================================
    // Access pixel and assign processed pixel into itd
    (*itd)[0]=255-bgr[0];
    (*itd)[1]=255-bgr[1];
    (*itd)[2]=255-bgr[2];
  }

  // ======================================================================
  imshow("img",img);
  waitKey(0);

  // ======================================================================
  return 0;
}
