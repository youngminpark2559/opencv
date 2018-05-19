// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 001_Introduce_006_basic_processing_load_image_and_show.cpp
// https://www.youtube.com/watch?v=136k2XdEeGM&index=9&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// ===========================================================================================
// Concepts
// ===========================================================================================
// 1. Illustration describing pixels with RGB channel
// img 2018-05-18 17-03-33.png
// </xmp><img src="https://raw.githubusercontent.com/youngmtool/cv/master/jhkim/pic/2018-05-18%2017-03-33.png"><xmp>

// ===========================================================================================
// Codes
// ===========================================================================================
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int,char)
{
    // You create one empty window named img
    namedWindow("img",0);
    namedWindow("img2",0);

    // c img : May type object, ss.jpg
    Mat img=imread("ss.jpg");
    Mat img2;
    // This flip image in horizontal direction
    flip(img,img2,1);

    // You will use sobel edge to change image
    // img : original image
    // img2 : image where changed image will be stored
    Sobel(img,img2,img,depth(),1,0)

    // You throw image onto empty img window
    imshow("img",img)
    imshow("img2",img2)

    // Without this, img window instantly shuts down
     // Real functionality of this is to wait key press
    // 0 : window waits for key press during infinite time
    // 1000 : window waits for key press during 1 second
    waitKey(0);

    // After key press, this shuts down all windows
    destroyAllWindows()

    return 0;
}
