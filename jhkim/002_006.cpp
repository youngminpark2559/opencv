// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// write image file, write video file
// 002_006.cpp
// https://www.youtube.com/watch?v=7HNK9TAuRj8&index=16&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// =======================================================================
// Concepts
// =======================================================================

// =======================================================================
// how to write image file
// =======================================================================

Mat img=imread("ss.jpg");
vector<Mat> rgbMat(3);
cv::split(img,rgbMat);

namedWindow("img",0);
imshow("img",rgbMat[2]);
waitKey(0);

imwrite("r.jpb",rgbMat[2]);
imwrite("g.bmp",rgbMat[1]);
imwrite("b.jpb",rgbMat[0]);

// =======================================================================
// Codes
// =======================================================================
#include "opencv2/opencv.hpp"
#include "opencv2/cuda.hpp"
#include "opencv2\cudaarithm.hpp"

#include <iostream>

using namespace std;
using namespace cv;

int main(int,char)
{
    // color case
    Mat img=imread("ss.jpg");
    namedWindow("img",0);

    imshow("img",img);
    waitKey(0);

    // You can use imwrite to save image
    // 1 arg : file name you want, 
    // including file name extension determining file format
    // 2 arg : Mat variable
    imwrite("new_img.png",img)
    imwrite("new_img.bmp",img)

    // =======================================================================
    // You will perform image processing
    // =======================================================================

    // =======================================================================
    //      Sobel edge
    // =======================================================================

    Mat img2;
    Sobel(img,img2,CV_8U,1,0);
    imwrite("sobel_img.png",img2)

    // =======================================================================
    //      deal with 3 channel with 3 vectors
    // =======================================================================

    vector<Mat> rgbMat(3);
    // img has 3 channel color
    // You will split 3 channel img, and assign each value into each vector
    split(img,rgbMat)
    imwrite("r.jpg",rgbMat[2]);
    imwrite("g.bmp",rgbMat[1]);
    imwrite("b.tif",rgbMat[0]);

    cout<<img.channels()<<endl;
    // 3 channel
    cout<<rgbMat[2].channels()<<endl;
    // 1 channel

    // =======================================================================
    // You will write video file
    // =======================================================================

    // When you read cam or video, you use VideoCapture
    VideoCapture capture(".\\rhinos.avi");
    // c frame : obtains one frame by one frame from rhinos.avi
    Mat frame;

    // Set properties
    int askFileTypeBox=0;
    //-1 is showing box of codec
    // int askFileTypeBox=-1;
    int Color=1;
    Size S=Size(
        (int)capture.get(CV_CAP_PROP_FRAME_WIDTH).
        (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));
    
    // You create output video file, named outVideo.avi
    // c outVideo : VideoWriter type variable, obtains one frame by one frame to write video file
    VideoWriter outVideo;
    // c askFileTypeBox : do you want to show codec box?
    // -1 : codec box which requires you to choose codec
    // capture.get(CV_CAP_PROP_FPS) : how many frames per second?, 
    // same number of frame with original video in this case
    // S : size of width and height of video, same with original video in this case
    // Color : do you create video in grayscale or color?
    outVideo.open(".\\outVideo.avi",askFileTypeBox,capture.get(CV_CAP_PROP_FPS),S,Color);

    // Check
    if(!capture.isOpened())
    {
        printf("AVI file can not open\n");
        return 0;
    }

    // create window
    namedWindow("w");

    while (1)
    {
        // grab frame from file and throw to Mat
        capture >> frame;

        // is video end?
        if(frame.empty())
            break;

        // You perform Sobel edge on video
        Sobel(frame,frame,frame.depth(),1,0);

        outVideo.write(frame);
        // You move one frame into outVideo in left direction, writing frame into disk, C++ syntax
        outVideo<<frame;
        // You can use following code instead of C++ style
        // outVideo.write(frame);
        // display and delay
        imshow("w",frame);
        if (waitKey(10)>0)
            break;
    }
    return 0;
}
