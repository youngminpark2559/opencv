// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 004_point_processing_001_of_008_constant_operation.cpp
// https://www.youtube.com/watch?v=Riy6szBqUIw&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2
// 004_point_processing_002_of_008_constant_operation.cpp
// https://www.youtube.com/watch?v=X5kpC1Vhy_0&index=26&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2
// 004_point_processing_003_of_008_Parallel_processing_for_point_adding.cpp
// https://www.youtube.com/watch?v=TXyIZvYiLHw&index=27&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 1. You will learn how to perform "constant operation (+,-,*,/)" of value of frame
// 1. You will learn how to process (operate) pixels between frame (images)
// 1. You will learn how to perform "other kind of operation (and, or, xor)"
// 1. You will learn how to generate ramdom noise onto frame

// @
// 1. You will learn how to perform "constant operation (+,-,*,/)" of value of frame

// @
// =================================================================
// Add
// =================================================================
// When you add value of frame, you can use add() which is provided by OpenCV
// You can also use add() of cuda::
// Without add(), you can perform Mat class + scalar value (x,x,x,...) to add constant value onto frame

// @
// =================================================================
// Subtract
// =================================================================
// When you subtract value of frame, you can use subtract() which is provided by OpenCV
// You can also use subtract() of cuda::

// @
// When you subtract value of frame, you can use subtract() which is provided by OpenCV
// You can also use subtract() of cuda::

// Note that when you perform add() and subtract(),
// if result of operation is less than 0, result will be 0,
// if result of operation is greater than 255, result will be 255

// =================================================================
// Absdiff
// =================================================================
// @
// You can use absdiff()
// For example, |6-7|=|-1|=1, final result is 1
// You also can you Cuda::absdiff

// @
// =================================================================
// Multiply and Divide
// =================================================================
// * and /
// You can use multiply(), divide()
// Or, you can operator (*,/)
// For example, A=A*Scalar, B=B/Scalar

// =================================================================
// paralle_for_
// =================================================================
// So far, processing and operating each pixel don't have correlation
// So, you don't need to process and operate pixel in consecutive order
// That means you can process and operate pixel in parallel way
// If you use parallel_for_(), you can process pixel in parallel within cpu environment

// void parallel_for_(const Range& range,const ParallelLoopBody& body,double nstripes=-1.)
// This method creates body by inheriting ParallelLoopBody parent class
// Parallel processing is made by range

// @
// =================================================================
// You will see above concepts on code
// =================================================================
// To use paralle_for_(), you should build code with including TBB

// You inherit ParallelLoopBody class
class Parallel_process : public cv::ParallelLoopBody
{
// =================================================================
// You define member variables
// =================================================================
private:
    // This is for input
    cv::Mat& inImg;
    // This is for output
    cv::Mat& outImg;
    // This is for width step
    int widhStep;
    int m_stride;
    cv::Scalar scalar; //B,G,R

public:
    // This is construct for this class
    // Constuctor will get,
    // input image (inputImgage),
    // output image (outImage) which will be exported,
    // sclar value (inScalar) which you want to add
    Parallel_process(cv::Mat& inputImgage, Mat& outImage, Scalar& inScalar)
        : inImg(inputImgage), outImg(outImage), scalar(inScalar){
        // You calculate widthstep inside of constructor
        // Since widthstep is value for color, you multiply arbitrary value(3)
        widhStep = inputImgage.size().width * 3;
        m_stride = inputImgage.size().width * 2;
    }

    // You overrides operator()
    virtual void operator()(const cv::Range& range) const
    {
        // Outer for loop is for using multi threads
        // Simply get you perform processing logic on 1st group data 
        // (all pixels located in first row) in 1st for loop execution
        for (int i = range.start; i < range.end; i++)
        {   
            // c i: starting point of each row
            // c s1: from starting point of each row, you go further as much as widhStep
            int s1 = i*widhStep;
            // Inner for loop is for executing real processing logic
            for (int iw = 0; iw< inImg.size().width; iw++)
            {   
                // c iw: Each corresponding pixel
                // You multiply 3 by each corresponding pixel because you're using rgb
                // c s2: each pixel which is multiplied by 3
                int s2 = iw * 3;
                // c mc: (pixel which is moved from previous pixel as much as 3) + (pixel multiplied by 3)
                int mc = s1 + s2;

                // When you use 0, it means you bring b value
                unsigned char B1 = (unsigned char)(inImg.data[mc + 0]);
                // When you use 1, it means you bring g value
                unsigned char G1 = (unsigned char)(inImg.data[mc + 1]);
                // When you use 2, it means you bring r value
                unsigned char R1 = (unsigned char)(inImg.data[mc + 2]);
                
                // c B2: you add extracted B1 and passed scalar value(2)
                // Since scalar uses rgb, you should extract b value from scalar,
                // and that is 2 index
                int B2 = B1 + scalar[2];
                // c G2: you add extracted G1 and passed scalar value(1)
                int G2 = G1 + scalar[1];
                // c R2: you add extracted R1 and passed scalar value(0)
                int R2 = R1 + scalar[0];

                // You process crop
                // If result B2 is greater than 255, you assign 255 into B2
                if (B2 > 255)
                    B2 = 255;
                if (G2 > 255)
                    G2 = 255;
                if (R2 > 255)
                    R2 = 255;

                if (B2 < 0)
                    B2 = 0;
                if (G2 < 0)
                    G2 = 0;
                if (R2 < 0)
                    R2 = 0;

                // You assgin processed values into output image
                outImg.data[mc + 0] = B2;
                outImg.data[mc + 1] = G2;
                outImg.data[mc + 2] = R2;
            }
        }
    }
};


#include "opencv2/opencv.hpp"
// You include cuda.hpp header file
#include "opencv2/cuda.hpp"
#include "opencv2/cudaarithm.hpp"
using namespace cv;

int main(int,char)
{   
    // These variables are used to compare processing time
    // c AAtime:
    // c BBtime:
    unsigned long AAtime = 0, BBtime = 0;

    Mat img=imread("scret.jpg");
    Mat img_add;

    // ======================================================================
    // You can use add() which is provided by OpenCV
    // ======================================================================
    // You can use add() to add scalar values onto image
    // Scalar value (r,g,b) should be between 0 and 255
    // R channel of each pixel will be added by 200
    // B channel of each pixel will be added by 200
    // G channel of each pixel will be added by 200
    // Then, you assign result into img_add
    // Since you add 200 onto each rgb channel of each pixel, 
    // you will see white image
    // add(img,Scalar(200,200,200),img_add);

    // Or, you can directly use + operator
    // img_add=img+Scalar(200,,200,200)

    // You will try add() by using cuda
    // First, you define cuda environment
    cuda::GpuMat gimg;
    cuda::GpuMat gout1,gout2;
    // Then, you upload image by using cuda
    // For this, you need to include cudaarithm.hpp
    gimg.upload(img);
    // Way of adding scalar values is similar
    cuda::add(gimg,Scalar(200,200,200),gout1);
    // Then, you should go down to cpu environment from cuda environment
    gout1.download(img_add);

    // You will compare processing time with gpu to processing with cpu
    // For this, you define variable, unsigned long AAtime = 0, BBtime = 0;
    // You will measure time of add with cuda
    AAtime = getTickCount();
    gimg.upload(img);
    cuda::add(gimg,Scalar(200,200,200),gout1);
    gout1.download(img_add);
    BBtime=getTickCount();
    printf("cuda add %.2lf sec \n",(BBtime-AAtime)/getTickFrequency());
    // cuda add 0.76 sec


    // You will measure time of add with cpu
    AAtime=getTickCount();
    add(img,Scalar(200,200,200),img_add)
    printf("cpu add %.2lf sec \n",(BBtime-AAtime)/getTickFrequency());
    Btime=getTickCount();

    // ======================================================================
    // You can use subtract() which is provided by OpenCV
    // ======================================================================
    AAtime = getTickCount();
    subtract(img, Scalar(200, 200, 200), img_subtract);
    // You can simply use - operator
    //img_subtract = img - Scalar(200, 200, 200)
    // Actually if you use negative values with add(), it's same to use subtract()
    BBtime = getTickCount();
    printf("subtract %.2lf sec \n", (BBtime - AAtime) / getTickFrequency()); //check processing time   

    // You will try subtract() by using cuda
    Mat img_subtract;
    cuda::subtract(gimg,Scalar(200,200,200),gout1);
    gout1.download(img_subtract);


    // =================================================================
    // You will see multiply and divide
    // =================================================================
    Mat img_mul,img_div;
    // You multiply 20 by each pixel of original image,
    // then assign result into img_mul
    // Note that you use unsigned character as value,
    // so, when value exceeds 255, exceeding value is filled into result pixel
    multiply(img,20,img_mul);
    // You can use Scalar when you use multiply()
    multiply(img,Scalar(10,200,10),img_mul);
    // You can use operator
    img_mul=img*20;

    divide(img,20,img_div);

    // You can use cuda multiply and divide
    cuda::multiply
    cuda::divide

    // =================================================================
    // You will see absdiff()
    // =================================================================
    Mat img_absdiff();
    // You will get inverted image in rgb color
    absdiff(img,Scalar(255,255,255),img_absdiff)
    // You can use cuda abs, absdiff, absSum, ...
    // cuda::abs


    // =================================================================
    // You will process image in parallel way
    // =================================================================
    // At defining img_parallel variable 
    // which is used as parameter for output in Parallel_process object, 
    // there is no space in memory
    // However, when you try to access to memory and assign value with following codes:
    // outImg.data[mc + 0] = B2;
    // outImg.data[mc + 1] = G2;
    // outImg.data[mc + 2] = R2;
    // you will get error
    Mat img_parallel;
    // So, to resolve above issue, 
    // you can create trash valued image which has same size and type with original image
    img_parallel = Mat(img.size(), img.type());
    
    // Parallel_process which you created from above
    // c img: original image
    cv::parallel_for_(cv::Range(0, img.rows), Parallel_process(img, img_parallel, Scalar(-200, -200, -200)));


    // =================================================================
    // This part is for showing images
    // =================================================================
    // This shows original image
    imshow("img", img);
    imshow("img_add", img_add);
    imshow("img_subtract", img_subtract);
    imshow("img_mul", img_mul);
    imshow("img_div", img_div);
    imshow("img_absdiff", img_absdiff);
    imshow("img_parallel", img_parallel);
    waitKey(0);

    return 0;
}
