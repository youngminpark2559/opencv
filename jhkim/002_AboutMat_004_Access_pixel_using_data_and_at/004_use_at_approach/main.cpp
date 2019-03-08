// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_004_Access_pixel_using_data_and_at/004_use_at_approach && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_004_Access_pixel_using_data_and_at/004_use_at_approach/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l


// ======================================================================
// You can access pixels by using following methods

// 1. at: safe but most slow
// 2. ptr: faster than ptr
// 3. data: fastest but unsafe
// 4. iterator: like STL

#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main(int,char)
{   
  // Create named window    
  namedWindow("img",1);

  // ======================================================================
  Mat img=imread("./../../universe.jpg");
  imshow("img",img);

  // =======================================================================
  // Invert image using at()

  for(int i=img.rows/10*2;i<img.rows/10*3;++i)
  {
    for(int j=0;j<img.cols;++j)
    {
      //Vec3b: unsigned character 3 channel, which is determined by image
      // See more type from
      // /usr/local/include/opencv2/core/matx.hpp
      // i stands for pixels in height
      // j stands for pixels in width
      unsigned char b=img.at<cv::Vec3b>(i,j)[0];
      unsigned char g=img.at<cv::Vec3b>(i,j)[1];
      unsigned char r=img.at<cv::Vec3b>(i,j)[2];

      img.at<cv::Vec3b>(i,j)[0]=(unsigned char)(255-b); //b
      img.at<cv::Vec3b>(i,j)[1]=(unsigned char)(255-g); //g
      img.at<cv::Vec3b>(i,j)[2]=(unsigned char)(255-r); //r
    }
  }
  imshow("img",img);
  waitKey(0);

  return 0;
}
