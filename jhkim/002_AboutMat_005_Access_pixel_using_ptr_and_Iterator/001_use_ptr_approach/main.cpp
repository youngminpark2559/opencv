// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_005_Access_pixel_using_ptr_and_Iterator/001_use_ptr_approach && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_005_Access_pixel_using_ptr_and_Iterator/001_use_ptr_approach/main.cpp \
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
  Mat img=imread("./../../universe.jpg");
  imshow("img",img);

  // =======================================================================
  // Invert image using ptr approach

  for(int i=img.rows/10*7;i<img.rows/10*8;i++) // Iterate all pixels in height 
  {
    // cv::Vec3b: data type of image
    // img.ptr<cv::Vec3b>(i): values of entire i-th row
    // c ptr: points i-th row
    cv::Vec3b *ptr=img.ptr<cv::Vec3b>(i);

    // You iterate img.cols times (width of image)
    for(int j=0;j<img.cols;j++) // Iterate all pixels in width
    {
      // get j-th column from i-th row
      // unsigned char b1=(ptr[j][0]);
      // unsigned char g1=(ptr[j][1]);
      // unsigned char r1=(ptr[j][2]);

      // Instead of using above one, you also can use this
      // This one is recommended
      cv::Vec3b bgr=ptr[j];
      unsigned char b1=(bgr[0]);
      unsigned char g1=(bgr[1]);
      unsigned char r1=(bgr[2]);

      ptr[j]=cv::Vec3b(255-b1,255-g1,255-r1);
    }
  }

  // ======================================================================
  imshow("img",img);
  waitKey(0);

  // ======================================================================
  return 0;
}
