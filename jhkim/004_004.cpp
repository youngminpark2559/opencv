// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 004_point_processing_004_of_008_arithmetic_operation_on_image.cpp
// https://www.youtube.com/watch?v=joanfNMFmOg&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2&index=28

// =================================================================
// Concepts
// =================================================================

// You can use addWeighted() to make composited image to look better
// src1 : first image
// alpha : weight in respect to first image
// src2 : second image
// beta : weight in respect to second image
// gamma : to increasen brighness
// dst : output image
void addWeighted(InputArray src1,double alpha,InputArray src2,double beta,double gamma,OutputArray dst,int dtype=-1)

// Formular is like:
// dst(I)=saturate(src1(I)*alpha+src2(I)*beta+gamma)
// It's recommended to make sum of 2 weights to be 1

// To achieve above goal, you can use following formular:
// $$$g(x)=(1-\alpha)f_{0}(x)+\alpha f_{1}(x)$$$


// =================================================================
// Practical code
// =================================================================
http://study.marearts.com/2017/02/cvlecture-example-code-operation.html
http://cvlecture.marearts.com/2017/02/opencv-lecture-4-4.html

#include "opencv2/opencv.hpp"
#include "opencv2/cuda.hpp"
#include "opencv2\cudaarithm.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int, char)
{   
    // =================================================================
    // You will perform operation on two images
    // =================================================================
    // c img: scret.jpg
    Mat img = imread("scret.jpg");
    // c img: scret2.jpg
    Mat img2 = imread("scret2.jpg");

    // You declare Mat type img_add variable
    Mat img_add;
    Mat img_wadd;
    Mat img_subtract;
    Mat img_mul;
    Mat img_div;

    // =================================================================
    // You will perform add operation on two images
    // =================================================================
    // You will resize img2 to have size of img1 to resolve below size issue
    resize(img2, img2, Size(img.size().width, img.size().height));
    // If you perform add() on 2 different sized images, you get error
    add(img, img2, img_add);
    // You can use operator
    //img_add = img + img2;
    // You can use cuda add
    //cuda::add(img_cuda, img2_cuda, img_add_cuda);

    // =================================================================
    // You will perform subtract operation on two images
    // =================================================================
    // When you subtract, result goes down from 255, 
    // resulting in sort of inverted image in color
    subtract(img, img2, img_subtract);
    //img_subtract = img - img2;
    //cuda::subtract(img_cuda, img2_cuda, img_subtract_cuda);
    
    // =================================================================
    // You will perform multiply operation on two images
    // =================================================================
    multiply(img, img2, img_mul);
    //img_mul = img * img2;
    //cuda::multiply(img_cuda, img2_cuda, img_mul_cuda);

    // =================================================================
    // You will perform divide operation on two images
    // =================================================================
    divide(img, img2, img_div);
    //img_div = img / img2;
    //cuda::divide(img_cuda, img2_cuda, img_div_cuda);


    // =================================================================
    // You will use addWeighted()
    // =================================================================

    // You define variables for weights
    double alpha = 0.5; 
    double beta;
    double input;

    // To make this interesting, you will get value of weight from client
    cout << "Input real number which will be used as weights, between 0 and 1 : ";
    cin >> input;

    // This is try catch statement
    if (input < 0.0)
        input = 0;
    else if (input > 1.0)
        input = 1.0;
        
    alpha = input;
    beta = (1.0 - alpha);
    addWeighted(img, alpha, img2, beta, 0.0, img_wadd);


    // You can make gradation effect from img1 to img2
    for (float w=0;w<1;w+=0.1)
    {
        alpha=w;
        beta=(1.0-alpha);
        addWeighted(img, alpha, img2, beta, 0.0, img_wadd);
        imshow("img_wadd",img_wadd);
        waitKey(500);
    }


    imshow("img", img);
    imshow("img2", img2);
    imshow("img_add", img_add);
    imshow("img_subtract", img_subtract);
    imshow("img_mul", img_mul);
    imshow("img_div", img_div);
    imshow("img_wadd", img_wadd);
    
    waitKey(0);
    return 0;
}
