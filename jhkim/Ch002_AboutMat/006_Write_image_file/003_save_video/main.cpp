// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_006_Write_image_file/003_save_video && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_006_Write_image_file/003_save_video/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int,char)
{
  // Mat img=imread("./../../../universe.jpg");
  // namedWindow("img",1);
  // imshow("img",img);

  // // ======================================================================
  // imwrite("new_img_png.png",img);
  // imwrite("new_img_bmp.bmp",img);

  // // ======================================================================
  // // Sobel edge
  // Mat img2;
  // Sobel(img,img2,CV_8U,1,0);
  // imwrite("new_img_sobel_png.png",img2);

  // // =======================================================================
  // // Deal with 3 channel with 3 vectors

  // // c rgbMat: create vector instance which has Mat objects as element
  // vector<Mat> rgbMat(3);

  // // img has 3 channel color
  // // You will split 3 channel-img, and assign each value into each vector
  // split(img,rgbMat);
  // imwrite("r.jpg",rgbMat[2]);
  // imwrite("g.bmp",rgbMat[1]);
  // imwrite("b.tif",rgbMat[0]);

  // // ======================================================================
  // cout<<img.channels()<<endl;
  // // 3 channel

  // cout<<rgbMat[2].channels()<<endl;
  // // 1 channel

  // =======================================================================
  // You will write video file

  VideoCapture capture("./../../overwatch.mp4");

  Mat frame;

  // Set properties
  int askFileTypeBox=0;
  //-1 is showing box of codec
  // int askFileTypeBox=-1;
  int Color=1;

  Size S=Size(
    (int)capture.get(CV_CAP_PROP_FRAME_WIDTH),
    (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));

  // ======================================================================
  // c outVideo: create VideoWriter instance
  VideoWriter outVideo;

  // askFileTypeBox: Do you want to show codec box?
  // -1: Codec box which requires you to choose codec
  // capture.get(CV_CAP_PROP_FPS): How many frames per second?
  // You will use same number of frames to the original video in this case
  // S: size of width and height of video, same with original video in this case
  // Color: Do you create video in grayscale or color?
  outVideo.open("./../../written_video.avi",askFileTypeBox,capture.get(CV_CAP_PROP_FPS),S,Color);

  // ======================================================================
  if(!capture.isOpened())
  {
    printf("AVI file can not open\n");
    return 0;
  }

  // ======================================================================
  // create window
  namedWindow("w");

  // ======================================================================
  while(1)
  {
    // Grab frame from video file and assign frame to Mat
    capture>>frame;

    // ======================================================================
    // Is video end?
    if(frame.empty())
    {
      break;
    }
      
    // ======================================================================
    // You perform Sobel edge on video
    Sobel(frame,frame,frame.depth(),1,0);

    // ======================================================================
    // Write frame to outVideo
    outVideo<<frame;

    // You can use following code instead of outVideo<<frame;
    // (But it didn't work for my test)
    // outVideo.write(frame);
    
    // ======================================================================
    imshow("w",frame);

    if(waitKey(10)==27)
    {
      break;
    }
  }
  return 0;
}
