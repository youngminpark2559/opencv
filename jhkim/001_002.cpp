// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 001_Introduce_002_How_to_start_OpenCV_download_and_setting.cpp
// https://www.youtube.com/watch?v=dOLyecCWFX8&index=5&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// ===========================================================================================
// Definition of terms
// ===========================================================================================
// Definition of computer vision:
// Computer perform activity (see, think, decide) of human, which is based on visuality

// Definition of OpenCV:
// A lot of reseaches which are needed for computer vision are implemented as library and OpenCV provides them

// ===========================================================================================
// How to use OpenCV (3 ways)
// ===========================================================================================
// 1. you can download opencv from official site:
// opencv.org/downloads.html
// then, you can use pre built dll files

// 1. You can build source code by yourself
// profits:
// You can generate code for your environment and your options
// For example, you can add cuda, TBB, OpenCL, Qt, extra modules, ...
// , which means you can build your own dll and libraries in taste

// 1. You can use Ceemple OpenCV
// Steps:
// Tools - Extension and Update
// Search ceemple - install
// Then, you can create OpenCV project in simple easy way

// ===========================================================================================
// You will actually try above ways
// ===========================================================================================
// You will test opencv2 and opencv3
// Go to opencv.org/downloads.html
// Download opencv2 exe and opencv3 exe

// Execute exe file to unzip file to specific folder where you want to unzip
// In this version, they're already performed in build
// You can see built dll files in opencv2413/opencv/build/x64/vc12/bin
// You can see built lib files in opencv2413/opencv/build/x64/vc12/lib
// You can see built header files in opencv2413/opencv/build/include/opencv2

// ===========================================================================================
// How to configure opencv library
// ===========================================================================================
// Go to project's property pages
// set configure as debug, flatform as x64
// Go to VC++ directory
// Set include directory (for header files) to opencv2413/opencv/build/include/
// Go to library directory
// Set include directory (for header files) to opencv2413/opencv/build/x64/vc12/lib/

// ===========================================================================================
// Practical code
// ===========================================================================================
// http://cvlecture.marearts.com/2016/12/opencv-lecture-1-2.html

#include < opencv2\opencv.hpp>
#include < stdio.h>

#ifdef _DEBUG        
#pragma comment(lib, "opencv_core320d.lib")
#pragma comment(lib, "opencv_imgproc320d.lib")   //MAT processing
#pragma comment(lib, "opencv_highgui320d.lib")
#pragma comment(lib, "opencv_imgcodecs320d.lib")
#pragma comment(lib, "opencv_videoio320d.lib")
#else
#pragma comment(lib, "opencv_core320.lib")
#pragma comment(lib, "opencv_imgproc320.lib")
#pragma comment(lib, "opencv_highgui320.lib")
#pragma comment(lib, "opencv_imgcodecs320.lib")
#pragma comment(lib, "opencv_videoio320.lib")
#endif   
 
using namespace std;
using namespace cv;

void main()
{
    // You load video file
    VideoCapture capture(".\\video.avi");

    Mat frame;
    
    // You check video can be open
    if (!capture.isOpened())
    {
        printf("AVI file can not open.\n");
        return;
    }
    // You create window
    namedWindow("w");
    
    while (1)
    {
        // You read video one frame by one frame
        // grab frame from file & throw to Mat
        capture >> frame;

        // Is video end?
        if (frame.empty()) 
            break;

        // You perform sobel edge effect
        Sobel(frame, frame, frame.depth(), 1, 0);

        // You display and delay
        imshow("w", frame);
        if (waitKey(10) > 0)
            break;
    }
}
