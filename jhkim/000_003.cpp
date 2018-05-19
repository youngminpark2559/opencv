// 000_build_003_build_setting_execute_sample_code.cpp
// https://www.youtube.com/watch?v=PhEzgRmk0xM&index=3&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// Once build has completed, 
// go to OpenCV_Library/build/bin/Debug and see dll files in debug version
// go to OpenCV_Library/build/bin/Release and see dll files in release version
// go to OpenCV_Library/build/lib/Debug
// go to OpenCV_Library/build/lib/Release

// To use OpenCV, you need Debug, lib, include files, header files
// You can see them in OpenCV_Library/source/opencv-master
// You can see them in OpenCV_Library/source/opencv_contrib-master

// It's recommend to collect all files into one folder
// There are several ways
// 1st way: you can manually copy all files and paste them into specific folder
// 2nd way:
// Find CMakeTargets and INSTALL in VS
// Execute "Build Only INSTALL" in respect to "Release"
// Execute "Build Only INSTALL" in respect to "Debug"
// * Then, you can gather all files into C:/OpenCV_Library/build/install/
// Go to C:/OpenCV_Library/build/install/include/ to see header files
// Go to C:/OpenCV_Library/build/x64/ to see dll files

// ===================================================================================
// How to deal with dll file when you execute exe file
// ===================================================================================
// 1. Locate dll files inside of Windows/System/
// 2. Use environment variable


// ===================================================================================
// You will create sample OpenCV application by using library which you've built
// ===================================================================================
// Win32 Console Application project
// Add cpp file
// Convert 64 bit mode because you built source with target to 64 bit
// Go to Property Pages to inform header file, lib file folder location
// Selct "All Configurations"
// Go to VC++ Directories
// Go to "Include Directories"
// Set directory with C:/OpenCV_Library/build/install/include/
// Go to "Library Directories"
// Set directory with C:/OpenCV_Library/build/install/x64/vc14/lib/
// Apply configuration

// * Go to Property Pages again
// Set "Configurations" to Debug
// Go to Linker and Input
// Write name of library as follow:
// opencv_core320d.lib
// opencv_imgproc320d.lib
// opencv_highgui320d.lib
// opencv_imgcodecs320d.lib
// opencv_videoio320d.lib

// Perform same above task with release but with removing "d"

// Or you can manually add files in the source code as code under using namespace cv;

// When you run into message saying no dll file,
// you should add corresponding dll files in project Projects/opencv_test/opencv_test/
// Also find tbb.dll and tbb.debug.dll file in tbb..../bin/intel64/vc14/ and add them into project folder

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

#ifdef _DEBUG
#pragma comment(lib,"opencv_core320d.lib")
#pragma comment(lib,"opencv_imgproc320d.lib")
#pragma comment(lib,"opencv_highgui320d.lib")
#pragma comment(lib,"opencv_imgcodecs320d.lib")
#pragma comment(lib,"opencv_videoio320d.lib")

#else
#pragma comment(lib,"opencv_core320.lib")
#pragma comment(lib,"opencv_imgproc320.lib")
#pragma comment(lib,"opencv_highgui320.lib")
#pragma comment(lib,"opencv_imgcodecs320.lib")
#pragma comment(lib,"opencv_videoio320.lib")
#endif

void main()
{
    // VideoCapture capture(0);
    // When you don't have camera, you can use video file
    VideoCapture capture("rhinos.avi");
    Mat frame;

    // check
    if (!capture.isOpened())
    {
        printf("AVI file can not open\n");
        return;
    }

    // create window
    namedWindow("w")

    while (1)
    {
        // grab frame from file and throw to Mat
        capture >> frame;
        // is video end?
        if (frame.empty())
            break;

        // processing example
        Sobel(frame,frame,frame.depth(),1,0);
    }
}

