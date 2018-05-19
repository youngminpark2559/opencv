// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 001_Introduce_007_how_to_access_pixel_data.cpp
// https://www.youtube.com/watch?v=ko7qN-k5yQQ&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// =======================================================================
// Way of accessing to pixel as matrix
// =======================================================================
// 1. At approach
// 2. Ptr approach
// 3. Data approach
// 4. Iterator approach

// =======================================================================
// 1. At approach
// =======================================================================
// Mat image (ROW, COL, CV_TYPE);
// image.at (WANT_ROW, WANT_COL);

// - ROW: Row
// - COL: Column
// - CV_TYPE: data type ( for example : CV_8UC3 = 8 bit 3 channels)
// - DATA_TYPE: Mat creation data type ( for example : float, usigned char)
// - WANT_ROW: access to the desired row
// - WANT_COL: access to the desired column

// [Advantage]: Access after validation progress, so safe way and accurate approach.
// [Disadvantage]: most slow in 3 ways.

// =======================================================================
// 2. Ptr approach
// =======================================================================
// Mat image (ROW, COL, CV_TYPE);
// image.ptr (WANT_ROW, WANT_COL); (This access is changed to the Point)

// - ROW: Row
// - COL: Column- CV_TYPE: data type ( for example : CV_8UC3 = 8 bit 3 channels)
// - DATA_TYPE: Mat creation data type ( for example : float, usigned char)
// - WANT_ROW: access to the desired row
// - WANT_COL: access to the desired column

// [Advantage]: 
// Access is faster than first way (At approach).
// [Disadvantage]: 
// direct access to the data, but way slower than third way (data approach), difficult to learn and use.

// =======================================================================
// 3. Data approach (using pointer)
// =======================================================================
// Mat image (ROW, COL, CV_TYPE);
// DATA_TYPE * data = (DATA_TYPE *) image.data;data [WANT_ROW * image.cols + WANT_COL]

// - ROW: Row
// - COL: Column
// - CV_TYPE: data type ( for example : CV_8UC3 = 8 bit 3 channels)
// - DATA_TYPE: Mat creation data type ( for example : float, usigned char)
// - WANT_ROW: access to the desired row
// - WANT_COL: access to the desired column

// [Advantage]: very fast.
// [Disadvantage]: not check validation, it is hard to know inadequate access.

// =======================================================================
// copy Vector to Mat, copy Mat to Vector
// =======================================================================

// =======================================================================
// This is sample code.
// =======================================================================
// http://study.marearts.com/2016/06/opencv-pixel-access-at-ptr-data.html


// =======================================================================
// OpenCV Pixel Access, at, ptr, data, iteration (example)
// =======================================================================
// I once wrote the following article.
// http://study.marearts.com/2014/04/opencv-study-mat-point-access-method.html
// This article is a sample code.

// c img : Mat type variable, ss.jpg file is assigned to
Mat img = imread("ss.jpg");
namedWindow("img", 0);

// =======================================================================
// using at
// =======================================================================
for (int i = img.rows / 10*3; i < img.rows / 10*4; ++i)
{
    for (int j = 0; j < img.cols; ++j)
    {
        // img.at : <Mat type>.at
        // cv::Vec3b : type which you want, Vec3b means 'uchar 3ch'
        // (i, j) : coordination for row and column
        // If you deal with 3 dimenstion due to rgb, you can deal with index
        // c b: extracted b value
        unsigned char b = img.at< cv::Vec3b>(i, j)[0];
        unsigned char g = img.at< cv::Vec3b>(i, j)[1];
        unsigned char r = img.at< cv::Vec3b>(i, j)[2];
        // printf("%d %d %d\n", b, g, r);

        // You invert image by subtracting 255 from b,g,r
        img.at< cv::Vec3b>(i, j)[0] = unsigned char(255 - b); //b
        img.at< cv::Vec3b>(i, j)[1] = unsigned char(255 - g); //g
        img.at< cv::Vec3b>(i, j)[2] = unsigned char(255 - r); //r
    }
}

// =======================================================================
// using ptr
// =======================================================================
for (int i = img.rows / 10 * 6; i < img.rows / 10 * 7; i++) 
{   
    // img.ptr
    // cv::Vec3b : type which you want
    // c ptr: extracted value
    cv::Vec3b* ptr = img.ptr< cv::Vec3b >(i);
    for (int j = 0; j < img.cols; j++) {
        cv::Vec3b bgr = ptr[j];
        unsigned char b = (bgr[0]);
        unsigned char g = (ptr[j][1]); //note!!
        unsigned char r = (bgr[2]);
        ptr[j] = cv::Vec3b(255 - b, 255 - g, 255 - r);
    }
}

// =======================================================================
// using data
// =======================================================================
for (int i = img.rows / 10 * 8; i < img.rows / 10 * 9; i++) 
{
    for (int j = 0; j < img.cols; j++) {
        unsigned char r, g, b;
        b = img.data[i * img.step + j * img.elemSize() + 0];
        g = img.data[i * img.step + j * img.elemSize() + 1];
        r = img.data[i * img.step + j * img.elemSize() + 2];
        img.data[i * img.step + j * img.elemSize() + 0] = unsigned char(255 - b);
        img.data[i * img.step + j * img.elemSize() + 1] = unsigned char(255 - g);
        img.data[i * img.step + j * img.elemSize() + 2] = unsigned char(255 - r);
    }
}

// =======================================================================
// using iteration
// =======================================================================
cv::MatIterator_< cv::Vec3b> itd = img.begin< cv::Vec3b>(), itd_end = img.end< cv::Vec3b>();
for (int i = 0; itd != itd_end; ++itd, ++i) 
{
    cv::Vec3b bgr = (*itd);
    (*itd)[0] = 255 - bgr[0];
    (*itd)[1] = 255 - bgr[1];
    (*itd)[2] = 255 - bgr[2];
}

imshow("img",img);
waitKey(0);
// ...

// input image
// output image

// =======================================================================
// copy Vector to Mat, copy Mat to Vector
// =======================================================================

int r=3;
int c=4;

// c Vf : vector type variable, element is float type
vector<float> Vf;

int cnt=0;
for(int i=0; i< c; ++i) 
    for(int j=0; j< r; ++j)
    {
        // You initialize vector by using push_back()
        // Vf.push_back(cnt++);
    }
    
// You create Mat with same size with above vector
// c M : (3,4) matrix, element is CV_32FC1
Mat M=Mat(r,c,CV_32FC1);

// You copy vector to mat
memcpy(M.data,Vf.data(),Vf.size()*sizeof(float));

// You print cloned Mat from vector
cout<<M<<endl;

// =======================================================================
// Mat to vector
// =======================================================================
vector<float> Vf2;
// You copy mat (M) into vector (Vf2)
Vf2.assign((float*)M.datastart,(float*)M.dataend);
 
// You can see result
cnt=0;
for(int i=0; i< c; ++i)
{
    for(int j=0; j< r; ++j)  
        printf("%lf ", Vf2[cnt++]);
    printf("\n");
}

// =======================================================================
// Image buffer(point) copy to Mat
// when you want to copy "unsigned char * pData" image buffer to Mat class in OpenCV.
// =======================================================================
// You first should sync size, data type between image buffer and Mat
Mat InImg(height, width, CV_8UC1);
// InImg.data : target
// pData : source
memcpy(InImg.data, pData, sizeof(unsigned char)*width*height);
