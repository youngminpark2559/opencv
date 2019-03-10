// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_004_Access_pixel_using_data_and_at/002_use_data_approach && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_004_Access_pixel_using_data_and_at/002_use_data_approach/main.cpp \
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
  // Invert image using data approach

  // Invert partial image
  // Start point of iteration is <img.rows/10*7>
  // End point of iteration is <img.rows/10*8>
  for(int i=img.rows/10*7;i<img.rows/10*8;i++) // Iterate all pixels in height 
  {
    // You iterate img.cols times (width of image)
    for(int j=0;j<img.cols;j++) // Iterate all pixels in width
    {
      unsigned char r,g,b;

      // Get BGR values from img
      // img.step: byte size
      b=img.data[i*img.step+j*img.elemSize()+0];
      g=img.data[i*img.step+j*img.elemSize()+1];
      r=img.data[i*img.step+j*img.elemSize()+2];

      // Process pixel values and assign them to img
      img.data[i*img.step+j*img.elemSize()+0]=(unsigned char)(255-b);
      img.data[i*img.step+j*img.elemSize()+1]=(unsigned char)(255-g);
      img.data[i*img.step+j*img.elemSize()+2]=(unsigned char)(255-r);
    }
  }

  // ======================================================================
  imshow("img",img);
  waitKey(0);

  // ======================================================================
  return 0;
}
