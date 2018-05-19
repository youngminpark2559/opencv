// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 002_AboutMat_001_load_image_and_video_and_show_them.cpp
// https://www.youtube.com/watch?v=b9o_1TfPtgI&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2&index=11

// =======================================================================
// Concept
// =======================================================================

// =======================================================================
// Image Reading
// =======================================================================

// You can use imread()
Mat img=imread("ss.jpg");
// You can load image in grayscale (black and white, 1 channel)
// But you also can create black and white with 3 channel,
// if you designate values of rgb with same value 
// Mat img=imread("ss.jpg",0);
namedWindow("img",0);
imshow("img",img)
waitKey(0)

// =======================================================================
// Video Reading
// =======================================================================

// You open default camera
VideoCapture cap(0)
// You open video file
VideoCapture cap("rhinos.avi")

// You check if video is opened
if (cap.isOpened())
{
    return -1;
}

namedWindow("video",1);

for (;;)
{
    Mat frame;
    // You get new frame from camera
    cap>>frame;
    imshow("video",frame);
    if(waitKey(30)>=0)
    {
        break;
    }
}

// Camera will be automatically deinitialized in VideoCapture destructor
return 0;


// =======================================================================
// Codes
// =======================================================================

#include "opencv2/opencv.hpp"

using namespance cv;
using namespance std;

int main(int,char)
{
    Mat img=imread("ss.jpg");
    // Mat img=imread("ss.jpg",0);
    // You can resize window by option 0
    // 1: can allow resize window
    namedWindow("imageWindow",0);
    imshow("imageWindow",img)

    while(1)
    {
        int keyValue;
        keyValue=waitKey(0);
        cout<<keyValue<<endl;
        if (keyValue=="c")
            break;
    }
    
    // =======================================================================
    // Load video file and display
    // =======================================================================

    VideoCapture capture(".\\cat.avi");
    // c frame : Mat type variable, at the moment, empty
    Mat frame;

    if(!capture.isOpened())
    {
        printf("AVI file can not open.\n");
        return 0;
    }
 
    // You create empty window
    namedWindow("w");
 
    while(1)
    {
        // You copy one frame (capture) into frame variable
        capture >> frame;
        // If video reaches to end point, 
        // there is no more frame copied from capture,
        // so, this stands for end of video
        if(frame.empty())
            // Out of while loop
            break;
    }
    // You process example video
    Sobel(frame,frame,frame.depth(),1,0);

    // display and delay
    imshow("w", frame);
    // http://study.marearts.com/2016/11/keycode-and-ascii-code.html
    // if(waitKey(10) > 0)
    // When you press esc (27)
    if(waitKey(10) == 27)
        break;
}
