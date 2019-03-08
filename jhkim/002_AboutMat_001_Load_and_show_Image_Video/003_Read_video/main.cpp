// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/002_AboutMat_001_Load_and_show_Image_Video/003_Read_video && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/002_AboutMat_001_Load_and_show_Image_Video/003_Read_video/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

#include "opencv2/opencv.hpp"
#include <iostream>
#include <cstring>
using namespace cv;
using namespace std;
 
int main()
{
  // Read video file
  VideoCapture capture("./../../overwatch.mp4");
  // VideoCapture capture(0);
  
  // ======================================================================
  Mat frame;

  // ======================================================================
  // Video file is opened?
  if(!capture.isOpened())
  {
    // Display fail message if video file is not loaded
    printf("AVI file can not open.\n");
    return 0;
  }

  // ======================================================================
  // You create empty window
  namedWindow("w",1);
  
  // ======================================================================
  // Read frames from the video file
  while(1)
  {
    // You copy one frame (capture) into frame variable
    capture>>frame;
    
    // If video reaches to the end point, 
    // there is no more frame 
    // which will be copied from "capture" into "frame",
    if(frame.empty())
    {
      break;
    }

    // ======================================================================
    // You apply Sobel into the video
    Sobel(frame,frame,frame.depth(),1,0);

    // ======================================================================
    imshow("w",frame);
    
    // Important: if you use waitKey(0), while loop gets stuck, 
    // with waiting for your key press
    // 27 as ASCII code stands for ESC key
    if(waitKey(10)==27)
    {
      break;
    }
  }

  // ======================================================================
  return 0;
}
