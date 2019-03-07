// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/001_Introduce_006_basic_processing_load_image_and_show/001 && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/001_Introduce_006_basic_processing_load_image_and_show/001/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ===========================================================================================
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main(int,char)
{
  // You create empty windows named img and img2
  namedWindow("img",0);
  namedWindow("img2",0);

  // ======================================================================
  // c img : create May instance which stores universe.jpg
  Mat img=imread("universe.jpg");
  // imshow("img",img);
  // waitKey(0);

  // c img2: Processed image will be stored in img2
  Mat img2;
  
  // ======================================================================
  // This flips image in horizontal direction
  flip(img,img2,1);
  // imshow("img2",img2);
  // waitKey();

  // ======================================================================
  // You will use sobel edge filter to filpped image.
  // img: original image.
  // img2: sobel-filter-affected image
  Sobel(img,img2,img.depth(),1,0);

  // ======================================================================
  // You display images onto img and img2 windows
  // imshow("img",img);
  // imshow("img2",img2);

  // ======================================================================
  // Without this, img window instantly shuts down
  // Real functionality of this is to wait key press from an user
  // 0: window waits for key pressing during infinite time
  // 1000: window waits for key pressing during 1 second
  waitKey(0);

  // ======================================================================
  // After key pressed, this shuts down all windows.
  destroyAllWindows();

  return 0;
}
