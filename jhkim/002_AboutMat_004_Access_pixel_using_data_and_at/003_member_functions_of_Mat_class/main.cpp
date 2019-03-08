// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_004_Access_pixel_using_data_and_at/003_member_functions_of_Mat_class && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_004_Access_pixel_using_data_and_at/003_member_functions_of_Mat_class/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
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
  // img.elemSize(): byte size of one pixel
  cout << img.elemSize() << endl;
  // 3 bytes

  // ======================================================================
  // img.channels(): kind of channel which current image uses
  // RGB is 3 channels, RGB+alpha is 4 channels
  cout << img.channels() << endl;
  // 3 channel

  // ======================================================================
  // img.rows: width length of image
  cout << img.rows << endl;
  // 456 rows

  // ======================================================================
  // img.step: byte size of one column?
  cout << img.step << endl;
  // 1896 bytes

  return 0;
}
