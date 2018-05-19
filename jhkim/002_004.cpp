// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// how to access data (pixel) in Mat type (at,ptr,data,iterator like STL)
// 002_004.cpp
// https://www.youtube.com/watch?v=BKDGjkUuujE&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2&index=14

// =======================================================================
// Concepts
// =======================================================================

// 1. at : safe but most slow
// 1. ptr : faster than ptr
// 1. data : fastest but unsafe
// 1. iterator : like STL

// =======================================================================
// Codes
// =======================================================================

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int, char)
{   
    namedWindow("img", 1);
    // c img : Mat type variable, anapji.jpg
    Mat img = imread("anapji.jpg");
    
    if (img.depth() == CV_8U)
        printf("8bit unsigend\n");

    // =======================================================================
    // Member methods and variables from Mat
    // =======================================================================
   
    // img.elemSize() : size of one pixel (byte) 
    // cout << img.elemSize() << endl;
    // 3 bytes

    // img.channels() : kind of channel which image uses
    // rgb is 3 channel, rgb+alpha is 4 channel
    // cout << img.channels() << endl;
    // 3 channel

    // img.rows : number of row which image has
    // cout << img.rows << endl;
    // 456 rows

    // img.step : size of width (byte)
    // cout << img.step << endl;
    // 1896 bytes

    // =======================================================================
    // using data
    // =======================================================================
    
    // You iterate img.rows times (height of image)
    // for (int i = 0; i < img.rows ; i++) {

    // You iterate partially,
    // start point of iteration is img.rows / 10 * 7
    // end point of iteration is img.rows / 10 * 8
    // img 2018-05-19 10-23-20.png
    for (int i = img.rows / 10 * 7; i < img.rows / 10 * 8; i++) 
    {
        // You iterate img.cols times (width of image)
        for (int j = 0; j < img.cols; j++)
        {
            unsigned char r, g, b;
            // c b : extracted b value from image
            // c img.step : real size of byte of image, including multiplication by 3
            // c img.elemSize() : size of one element's channel color (3 in this case due to rgb channel)
            b = img.data[i * img.step + j * img.elemSize() + 0];
            g = img.data[i * img.step + j * img.elemSize() + 1];
            r = img.data[i * img.step + j * img.elemSize() + 2];

            // You subtract b by 255 to invert image, then assign result into location of pixel
            img.data[i * img.step + j * img.elemSize() + 0] = unsigned char(255 - b);
            img.data[i * img.step + j * img.elemSize() + 1] = unsigned char(255 - g);
            img.data[i * img.step + j * img.elemSize() + 2] = unsigned char(255 - r);
        }
    }
    
    // =======================================================================
    // using at
    // =======================================================================
    
    // You will invert image only in 2/10 to 3/10 location
    // img 2018-05-19 10-32-18.png
    for (int i = img.rows / 10 * 2; i < img.rows / 10 * 3; ++i)
    {
        for (int j = 0; j < img.cols; ++j)
        {
            //Vec3b : unsigned character 3 channel, which is determined by image
            // i : row of image matrix, height of image
            // j : column of image matrix, width of image
            // (i, j)[0] : (i,j) element of matrix, 0th value from bgr channel
            unsigned char b = img.at<cv::Vec3b>(i, j)[0];
            unsigned char g = img.at<cv::Vec3b>(i, j)[1];
            unsigned char r = img.at<cv::Vec3b>(i, j)[2];

            //printf("%d %d %d\n", b, g, r);
            img.at<cv::Vec3b>(i, j)[0] = unsigned char(255 - b); //b
            img.at<cv::Vec3b>(i, j)[1] = unsigned char(255 - g); //g
            img.at<cv::Vec3b>(i, j)[2] = unsigned char(255 - r); //r
        }
    }

    // =======================================================================
    // using ptr
    // =======================================================================
    
    // img 2018-05-19 10-39-23.png
    for (int i = img.rows / 10 * 5; i < img.rows / 10 * 6; i++) 
    {   
        // c cv::Vec3b : type of image
        // img.ptr<cv::Vec3b>(i) : entire data of ith row from image matrix
        // ptr : Vec3b type pointer variable, indicating ith row
        cv::Vec3b* ptr = img.ptr<cv::Vec3b>(i);

        // For loop for column (width of image)
        for (int j = 0; j < img.cols; j++) 
        {
            // Bring value from jth column from ptr
            // [0] : channel
            unsigned char b1 = (ptr[j][0]);
            unsigned char g1 = (ptr[j][1]); //note!!
            unsigned char r1 = (ptr[j][2]);

            // Instead of above code, you also can use following code
            // Now, ptf is indicating ith row
            // From ith row, you assign jth column int bgr
            // This is more recommended to use
            cv::Vec3b bgr = ptr[j];
            unsigned char b2 = (bgr[0]);
            unsigned char g2 = (bgr[1]); //note!!
            unsigned char r2 = (bgr[2]);

            // You assign results into jth column
            ptr[j] = cv::Vec3b(255 - b1, 255 - g1, 255 - r1);
        }
    }

    // =======================================================================
    // using iteration
    // =======================================================================
    // cv::Vec3b : data type of image
    // itd : MatIterator_ type variable
    // You assign begin of image, end of image into itd to create iterator
    cv::MatIterator_<cv::Vec3b> itd=img.begin<cv::Vec3b>(), itd_end=img.end<cv::Vec3b>();

    // You invert entire image which you've been processing
    // img 2018-05-19 10-45-55.png
    // You increment iterator until you meet end of image
    // ++i : You actually are not using this in code, but helpful to check current step
    for (int i = 0; itd != itd_end; ++itd, ++i)
    {   
        // c bgr : Place which iterator itd is pointing to
        cv::Vec3b bgr = (*itd);

        // You access to values of bgr
        // (*itd)[0] : 0th place which iterator pointing to
        (*itd)[0] = 255 - bgr[0];
        (*itd)[1] = 255 - bgr[1];
        (*itd)[2] = 255 - bgr[2];
    }
    
    // show
    imshow("img", img);
    waitKey(0);

    destroyAllWindows();

    return 0;
}
