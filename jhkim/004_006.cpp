// 004_point_processing_006_of_008_and_or_xor_operation_on_image.cpp
// https://www.youtube.com/watch?v=47wqbh0ykrE&index=30&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// =================================================================
// Concepts
// =================================================================
// You can implement "bit operation (and,or,xor,not)" 
// with following methods which are provided by OpenCv:
// bitwise_and
// bitwise_or
// bitwise_xor
// bitwise_not

// However, note that size and channel must be same

// =================================================================
//      Mat setTo and copyTo
// =================================================================

// =================================================================
//              setTo()
// =================================================================
// Mat class has member methods like setTo() and copyTo()
// You can use setTo() when you initialize value from Mat
// Image
// yy=
//     2 2 2
//     2 2 2
//     2 2 2

// Mask
// xx=
//     0 0 0
//     0 1 0
//     0 0 0

// Location of 1 from mask will be applied to image, 
// with changing value to specified value (0 in this case)
// yy.setTo(0,xx) returns:
// yy=
//     2 2 2
//     2 0 2
//     2 2 2


// =================================================================
//              copyTo()
// =================================================================
// copyTo() is used when you copy value

// Image
// yy=
//     2 2 2
//     2 2 2
//     2 2 2

// Mask
// xx=
//     0 0 0
//     0 1 0
//     0 0 0

// yy.copyTo(zz,xx) returns:
// zz=
//     0 0 0
//     0 2 0
//     0 0 0


// =================================================================
// Practical codes
// =================================================================

// http://study.marearts.com/2017/02/opencv-lecture-and-or-xor-not-example.html
// http://cvlecture.marearts.com/2017/02/opencv-lecture-4-6.html

#include <iostream>

using namespace std;
using namespace cv;


int main(int,char)
{
    // =================================================================
    // You will perform bit operation with 2 circles 
    // =================================================================

    // You create 2 circles with same size
    Mat leftCircle = Mat(500, 1000, CV_8UC1);
    Mat rightCircle = Mat(500, 1000, CV_8UC1);
    leftCircle.setTo(0);
    rightCircle.setTo(0);

    // You locate 2 circles with slightly horizontally different positions
    circle(leftCircle, Point(1000/5*2, 500/2), 250, CV_RGB(255, 255, 255), CV_FILLED);
    circle(rightCircle, Point(1000 / 5 * 3, 500 / 2), 250, CV_RGB(255, 255, 255), CV_FILLED);
    
    // =================================================================
    // You will test bit operations (and, or, xor, not)
    // =================================================================
    Mat res;
    // This method will remain only overlapped area from both left and right
    bitwise_and(leftCircle, rightCircle, res);     imshow("AND", res);
    // This method will remain peanut shape from left and right
    bitwise_or(leftCircle, rightCircle, res);      imshow("OR", res);
    // This method will remain only different area from left and right
    bitwise_xor(leftCircle, rightCircle, res);     imshow("XOR", res);
    // This method will remain inverted image from either left or right
    bitwise_not(leftCircle, res);                  imshow("NOT", res);

    imshow("leftCircle", leftCircle);
    imshow("rightCircle", rightCircle);

    waitKey(0);
    
    // =================================================================
    // You will perform masking process on real image
    // =================================================================
    // http://study.marearts.com/2017/02/opencv-lecture-and-or-xor-not-example_14.html
    // http://cvlecture.marearts.com/2017/02/opencv-lecture-4-6.html

    // Masking process means you use mask image, then apply mask image on real image

    // c img: real image which will be applied by mask image
    Mat img = imread("empireofthesun.jpg");
    // c img_mask: which has same size and channel type
    Mat img_mask = img.clone();
    // Or you can directly load mask image, if you set it in advance
    // imread("empireofthesun_mask.jpg");
    img_mask.setTo(0);
    circle(img_mask, Point(1000 / 5 * 2, 500 / 2), 250, CV_RGB(255, 255, 255), CV_FILLED);

    Mat res;
    bitwise_and(img, img_mask, res);     imshow("AND", res);
    bitwise_or(img, img_mask, res);      imshow("OR", res);
    bitwise_xor(img, img_mask, res);     imshow("XOR", res);
    bitwise_not(img, res);               imshow("NOT", res);

    imshow("img_mask", img_mask);
    imshow("img", img);

    waitKey(0);

    // =================================================================
    // You will use setTo()
    // =================================================================
    // http://study.marearts.com/2017/02/opencv-setto-copyto-masking-example.html
    // http://cvlecture.marearts.com/2017/02/opencv-lecture-4-6.html

    // c img2: loaded image, empireofthesun.jpg
    Mat img2 = imread("empireofthesun.jpg");
    // c img_mask_8: created mask with same size with loaded image
    Mat img_mask_8 = Mat(img2.rows, img2.cols, CV_8UC1); // imread("empireofthesun_mask.jpg");
    img_mask_8.setTo(0);
    circle(img_mask_8, Point(1000 / 5 * 2, 500 / 2), 250, CV_RGB(255, 255, 255), CV_FILLED);

    // You will convert color of original image to Scalar(255,0,255),
    // but convert color in only location by img_mask_8
    img2.setTo(Scalar(255,0,255), img_mask_8);
    // You can one scalar value than rgb value
    // img2.setTo(0, img_mask_8);
    
    // You can check shape of img_mask_8
    imshow("img_mask_8",img_mask_8)
    imshow("img2", img2);
    waitKey(0);

    // =================================================================
    // You will use copyTo()
    // =================================================================
    // http://study.marearts.com/2017/02/opencv-setto-copyto-masking-example.html
    // http://cvlecture.marearts.com/2017/02/opencv-lecture-4-6.html

    Mat img2 = imread("empireofthesun.jpg");

    Mat img_mask = Mat(img2.rows, img2.cols, CV_8UC1);
    img_mask.setTo(0);
    circle(img_mask, Point(1000 / 5 * 2, 500 / 2), 250, CV_RGB(255, 255, 255), CV_FILLED);

    Mat img3;
    // You will copy img2 and paste copied img2 on img3, but only location by img_mask
    img2.copyTo(img3, img_mask);
    imshow("img3", img3);
    waitKey(0);
}
