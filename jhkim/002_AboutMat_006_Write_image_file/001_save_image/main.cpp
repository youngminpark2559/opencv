// cd /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_006_Write_image_file/001_save_image && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /home/young/Desktop/git_ssh_opencv/opencv/jhkim/002_AboutMat_006_Write_image_file/001_save_image/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int,char)
{
  Mat img=imread("./../../universe.jpg");
  namedWindow("img",1);
  imshow("img",img);
  waitKey(0);

  // ======================================================================
  imwrite("new_img_png.png",img);
  imwrite("new_img_bmp.bmp",img);

  // ======================================================================
  // Sobel edge
  Mat img2;
  Sobel(img,img2,CV_8U,1,0);
  imwrite("new_img_sobel_png.png",img2);

  // =======================================================================
  // Deal with 3 channel with 3 vectors

  // vector<Mat> rgbMat(3);
  // // img has 3 channel color
  // // You will split 3 channel img, and assign each value into each vector
  // split(img,rgbMat)
  // imwrite("r.jpg",rgbMat[2]);
  // imwrite("g.bmp",rgbMat[1]);
  // imwrite("b.tif",rgbMat[0]);

  // cout<<img.channels()<<endl;
  // // 3 channel
  // cout<<rgbMat[2].channels()<<endl;
  // // 1 channel

  // // =======================================================================
  // // You will write video file
  // // =======================================================================

  // // When you read cam or video, you use VideoCapture
  // VideoCapture capture(".\\rhinos.avi");
  // // c frame : obtains one frame by one frame from rhinos.avi
  // Mat frame;

  // // Set properties
  // int askFileTypeBox=0;
  // //-1 is showing box of codec
  // // int askFileTypeBox=-1;
  // int Color=1;
  // Size S=Size(
  //     (int)capture.get(CV_CAP_PROP_FRAME_WIDTH).
  //     (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));

  // // You create output video file, named outVideo.avi
  // // c outVideo : VideoWriter type variable, obtains one frame by one frame to write video file
  // VideoWriter outVideo;
  // // c askFileTypeBox : do you want to show codec box?
  // // -1 : codec box which requires you to choose codec
  // // capture.get(CV_CAP_PROP_FPS) : how many frames per second?, 
  // // same number of frame with original video in this case
  // // S : size of width and height of video, same with original video in this case
  // // Color : do you create video in grayscale or color?
  // outVideo.open(".\\outVideo.avi",askFileTypeBox,capture.get(CV_CAP_PROP_FPS),S,Color);

  // // Check
  // if(!capture.isOpened())
  // {
  //     printf("AVI file can not open\n");
  //     return 0;
  // }

  // // create window
  // namedWindow("w");

  // while (1)
  // {
  //     // grab frame from file and throw to Mat
  //     capture >> frame;

  //     // is video end?
  //     if(frame.empty())
  //         break;

  //     // You perform Sobel edge on video
  //     Sobel(frame,frame,frame.depth(),1,0);

  //     outVideo.write(frame);
  //     // You move one frame into outVideo in left direction, writing frame into disk, C++ syntax
  //     outVideo<<frame;
  //     // You can use following code instead of C++ style
  //     // outVideo.write(frame);
  //     // display and delay
  //     imshow("w",frame);
  //     if (waitKey(10)>0)
  //         break;
  // }
  return 0;
}
