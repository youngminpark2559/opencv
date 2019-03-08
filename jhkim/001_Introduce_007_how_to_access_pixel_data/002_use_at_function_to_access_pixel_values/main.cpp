// cd /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/002 && \
// g++ `pkg-config --cflags opencv` \
// -o main \
// /mnt/1T-5e7/mycodehtml/cv/jhkim/001_Introduce_007_how_to_access_pixel_data/002/main.cpp \
// `pkg-config --libs opencv` &&\
// rm e.l && ./main 2>&1 | tee -a e.l && code e.l

// ======================================================================
// OpenCV Pixel Access, at, ptr, data, iteration (example)
// http://study.marearts.com/2014/04/opencv-study-mat-point-access-method.html

// ======================================================================
#include <iostream>
#include <cstring>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
 
int main()
{
  // ======================================================================
  // c img : Mat type instance, ss.jpg file is assigned to img.
  Mat img = imread("universe.jpg");
  namedWindow("img",0);

  // ======================================================================
  // Let's use at() to access to the pixel.

  for (int i = img.rows / 10*3; i < img.rows / 10*4; ++i)
  {
    for (int j = 0; j < img.cols; ++j)
    {
      // You get pixel values from "img"
      // cv::Vec3b: data type you're using.
      // 0,1,2: stands for BGR values.
      unsigned char b=img.at<cv::Vec3b>(i,j)[0];
      unsigned char g=img.at<cv::Vec3b>(i,j)[1];
      unsigned char r=img.at<cv::Vec3b>(i,j)[2];

      // ======================================================================
      // Let's invert the image by subtracting 255 from b,g,r values
      img.at<cv::Vec3b>(i,j)[0]=(255-b);
      img.at<cv::Vec3b>(i,j)[1]=(255-g);
      img.at<cv::Vec3b>(i,j)[2]=(255-r);
    }
  }

  imshow("img",img);
  waitKey(0);

  return 0;
}



// // ======================================================================
// //using ptr
// // ======================================================================
// for (int i = img.rows / 10 * 6; i < img.rows / 10 * 7; i++) 
// {   
//     // img.ptr
//     // cv::Vec3b : type which you want
//     // c ptr: extracted value
//     cv::Vec3b* ptr = img.ptr< cv::Vec3b >(i);
//     for (int j = 0; j < img.cols; j++) {
//         cv::Vec3b bgr = ptr[j];
//         unsigned char b = (bgr[0]);
//         unsigned char g = (ptr[j][1]); //note!!
//         unsigned char r = (bgr[2]);
//         ptr[j] = cv::Vec3b(255 - b, 255 - g, 255 - r);
//     }
// }

// // ======================================================================
// //using data
// // ======================================================================
// for (int i = img.rows / 10 * 8; i < img.rows / 10 * 9; i++) 
// {
//     for (int j = 0; j < img.cols; j++) {
//         unsigned char r, g, b;
//         b = img.data[i * img.step + j * img.elemSize() + 0];
//         g = img.data[i * img.step + j * img.elemSize() + 1];
//         r = img.data[i * img.step + j * img.elemSize() + 2];
//         img.data[i * img.step + j * img.elemSize() + 0] = unsigned char(255 - b);
//         img.data[i * img.step + j * img.elemSize() + 1] = unsigned char(255 - g);
//         img.data[i * img.step + j * img.elemSize() + 2] = unsigned char(255 - r);
//     }
// }

// // ======================================================================
// //using iteration
// // ======================================================================
// cv::MatIterator_< cv::Vec3b> itd = img.begin< cv::Vec3b>(), itd_end = img.end< cv::Vec3b>();
// for (int i = 0; itd != itd_end; ++itd, ++i) 
// {
//     cv::Vec3b bgr = (*itd);
//     (*itd)[0] = 255 - bgr[0];
//     (*itd)[1] = 255 - bgr[1];
//     (*itd)[2] = 255 - bgr[2];
// }

// imshow("img",img);
// waitKey(0);
// // ...



// // ======================================================================
// // copy Vector to Mat, copy Mat to Vector

// // This is sample code.
// // http://study.marearts.com/2016/06/opencv-pixel-access-at-ptr-data.html



// // copy Vector to Mat, copy Mat to Vector
// // ======================================================================

// int r=3;
// int c=4;

// // c Vf : vector type variable, element is float type
// vector<float> Vf;

// int cnt=0;
// for(int i=0; i< c; ++i) 
//     for(int j=0; j< r; ++j)
//     {
//         // You initialize vector by using push_back()
//         // Vf.push_back(cnt++);
//     }
    
// // You create Mat with same size with above vector
// // c M : (3,4) matrix, element is CV_32FC1
// Mat M=Mat(r,c,CV_32FC1);

// // You copy vector to mat
// memcpy(M.data,Vf.data(),Vf.size()*sizeof(float));

// // You print cloned Mat from vector
// cout<<M<<endl;

// // ======================================================================
// // Mat to vector
// // ======================================================================
// vector<float> Vf2;
// // You copy mat (M) into vector (Vf2)
// Vf2.assign((float*)M.datastart,(float*)M.dataend);
 
// // You can see result
// cnt=0;
// for(int i=0; i< c; ++i)
// {
//     for(int j=0; j< r; ++j)  
//         printf("%lf ", Vf2[cnt++]);
//     printf("\n");
// }

// // ======================================================================
// // Image buffer(point) copy to Mat
// // when you want to copy "unsigned char * pData" image buffer to Mat class in OpenCV.
// // ======================================================================
// // You first should sync size, data type between image buffer and Mat
// Mat InImg(height, width, CV_8UC1);
// // InImg.data : target
// // pData : source
// memcpy(InImg.data, pData, sizeof(unsigned char)*width*height);