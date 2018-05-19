// 004_point_processing_007_of_008_noise_generation.cpp
// https://www.youtube.com/watch?v=Hd0YCChDxOM&index=32&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// ===================================================================================
// Concepts
// ===================================================================================
// ===================================================================================
//      There are several random method in OpenCV:
// ===================================================================================
// 1. randn():
// You generate random value from data following gaussian distribution 
// You should input mean value and standard deviation value into randn()

// 1. randu():
// You generate random value from data ranged low and max value
// You should input low value and max value into randu()

// Result number type (interget, float, signed type, ...) from above 2 methods is determined 
// according to type of Mat variable which you're supposed to pass in

// ===================================================================================
//      You will see some example:
// ===================================================================================

// ===================================================================================
//           1. randn() with unsigned and 1 channel
// ===================================================================================
// c Gaussian_noise: Mat type, (5,5), usigned 1 channel
Mat Gaussian_noise=Mat(5,5,CV_8UC1);
// c mean: mean value of normal distribution
double mean=0;
// c std: std value of normal distribution
double std=10;
// randn() is taking Mat type Gaussian_noise variable
randn(Gaussian_noise,mean,std);
cout<<Gaussian_noise<<endl;
// [
//     0,2,0,0,12;
//     0,0,3,5,0;
//     8,0,13,0,0;
//     0,0,19,3,0;
//     15,0,0,0,0;
// ]

// ===================================================================================
//           1. randn() with signed and 1 channel
// ===================================================================================
Mat Gaussian_noise=Mat(5,5,CV_8SC1);
double mean=0;
double std=10;
randn(Gaussian_noise,mean,std);
cout<<Gaussian_noise<<endl;
// [
//     0,2,-7,-4,12;
//     -3,-6,3,5,-11;
//     8,0,13,-20,-19;
//     -5,-7,19,3,-14;
//     15,-8,-25,-15,-14;
// ]

// ===================================================================================
//           1. randn() with 32 bit float
// ===================================================================================
Mat Gaussian_noise=Mat(5,5,CV_32F);
double mean=0;
double std=10;
randn(Gaussian_noise,mean,std);
cout<<Gaussian_noise<<endl;

// ===================================================================================
//           2. randu() with unsigned and 1 channel
// ===================================================================================
Mat Gaussian_noise=Mat(5,5,CV_8UC1);
// low value 5
// max value 10
randu(Gaussian_noise,5,10)
cout<<Gaussian_noise<<endl;

// ===================================================================================
//           2. randu() with signed and 1 channel
// ===================================================================================
Mat Gaussian_noise=Mat(5,5,CV_8SC1);
// low value 5
// max value 10
randu(Gaussian_noise,5,10)
cout<<Gaussian_noise<<endl;

// ===================================================================================
//           2. randu() with 32 bit float
// ===================================================================================
Mat Gaussian_noise=Mat(5,5,CV_32F);
// low value 5
// max value 10
randu(Gaussian_noise,5,10)
cout<<Gaussian_noise<<endl;


// ===================================================================================
//           3. You will create noise on original image
// ===================================================================================
// 1. Since noise will be reflected by "and operation",
// 1. you should create Mat variable (noise) as same size with original image

Mat Gaussian_noise=mat(img.size(),img.type());
double mean=0;
double std=10;
randn(Gaussian_noise,mean,std);
Mat colorNoise=img+Gaussian_noise;

// ===================================================================================
// Practical code
// ===================================================================================
// http://study.marearts.com/2017/03/opencv-lecture-4-7-source-code-noise.html
// http://cvlecture.marearts.com/2017/03/opencv-lecture-4-7-noise-generation.html

#include "opencv2/opencv.hpp"
#include "opencv2/cuda.hpp"
#include "opencv2\cudaarithm.hpp"
#include <iostream>
#include <time.h>

using namespace std;
using namespace cv;

int main(int, char)
{

    // c img: Mat type, loaded image, jodie.jpg
    Mat img = imread("jodie.jpg");
    namedWindow("img", 0);
    imshow("img", img);

    // ===================================================================================
    // You will see noise from randn() and randu()
    // ===================================================================================
    // c Gnoise: Mat type variable, (5,5), signed and 1 channel, 
    // which will be used with gaussian distribution
    Mat Gnoise = Mat(5, 5, CV_8SC1);
    // mean, variance
    randn(Gnoise, 5, 10); 
    cout << Gnoise << endl;
    
    // c Unoise: Mat type variable, (5,5), signed and 1 channel,
    // which will be used with low and max value
    Mat Unoise = Mat(5, 5, CV_8SC1);
    // low, high
    randu(Unoise, 5, 10); 
    cout << Unoise << endl;

    //noise adapt
    Mat Gaussian_noise = Mat(img.size(), img.type());
    double mean = 0;
    double std = 10;
    // mean, std
    randn(Gaussian_noise, mean, std); 
    Mat colorNoise = img + Gaussian_noise;
    
    // ===================================================================================
    // You will see another way of noise
    // You will use for loop to plot random location white dot (255) on image
    // ===================================================================================
    // You will iterate 1000 times, that is, 1000 white dots
    int rsize = 1000;
    // You initialize random seed by using time 
    // which will be used as initial value for rand() 
    // This is way of using rand() in C++ standard way
    srand(time(NULL)); // #include <time.h>
    Mat imgD = img.clone();
    for (int i = 0; i < rsize; ++i)
    {
        // but x,y value will be duplicate
        int x = rand()%img.cols; // You will generate one random value from [0,img.cols-1]
        int y = rand()%img.rows; // You will generate one random value from [0,img.rows-1]

        cout << x << " " << y << " / " << img.cols << " " << img.rows << endl;

        // You will assign 255 (white) into each rgb channel
        imgD.at< Vec3b >(y, x)[0] = 255;
        imgD.at< Vec3b >(y, x)[1] = 255;
        imgD.at< Vec3b >(y, x)[2] = 255;

        // If you want to random colored dots,
        // but note that value of color should be between 0 and 255
        imgD.at< Vec3b >(y, x)[0] = rand()%255;
        imgD.at< Vec3b >(y, x)[1] = rand()%255;
        imgD.at< Vec3b >(y, x)[2] = rand()%255;

    }

    // ===================================================================================
    // Above way uses for loop which can be rather inefficient
    // You will see how to do same task with OpenCV
    // You will create noise with minMaxldx() and threshhold from OpenCV
    // ===================================================================================

    namedWindow("img", 0);
    imshow("img", img);

    namedWindow("colorNoise", 0);
    imshow("colorNoise", colorNoise);

    namedWindow("Gaussian_noise", 0);
    imshow("Gaussian_noise", Gaussian_noise);
    
    namedWindow("imgD", 0);
    imshow("imgD", imgD);

    //normalize(result, result, 0.0, 1.0, CV_MINMAX, CV_64F);
    //minMaxIdx(plan[i],&minIm,&maxIm);
    
    // c noiseGray: Mat type variable, you cloned original image
    Mat noiseGray = img.clone();
    // To reduce complexity of task, you convert Mat variable for noise into grayscale
    cvtColor(noiseGray, noiseGray, CV_RGB2GRAY);
    // c Gaussian_noise2: Mat type variable for noise
    Mat Gaussian_noise2 = Mat(noiseGray.rows, noiseGray.cols, CV_8UC1);
    double mean2 = 0;
    double std2 = 10;
    // You generate noise with mean and std value
    randn(Gaussian_noise2, mean2, std2); 
    double minV, maxV;
    // You bring min and max value
    minMaxIdx(Gaussian_noise2, &minV, &maxV);
    // You print min and max value
    cout << "min : " << minV << " max :" << maxV << endl;
    // You use threshhold() to plot random location dots
    // Criterion for threshhold : (minV + maxV) / 2
    // Less than criterion:0
    // Greater than criterion:1
    threshold(Gaussian_noise2, Gaussian_noise2, (minV + maxV) / 2, 255, CV_THRESH_BINARY);

    noiseGray = noiseGray + Gaussian_noise2;
    
    namedWindow("Gaussian_noise2",0);
    imshow("Gaussian_noise2", Gaussian_noise2);

    namedWindow("noiseGray", 0);
    imshow("noiseGray", noiseGray);

    waitKey(0);

    return 0;
}
