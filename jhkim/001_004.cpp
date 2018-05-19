// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 001_Introduce_004_Matrix_class_in_opencv.cpp
// https://www.youtube.com/watch?v=TwUIFeu7g-o&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2&index=7

// ===========================================================================================
// Concepts
// ===========================================================================================
// ===========================================================================================
// Mat class
// ===========================================================================================
// You can consider image as mathematical matrix,
// so opencv process image as matrix
// To deal with matrix, Mat class is basic class in OpenCV

// ===========================================================================================
// Codes
// ===========================================================================================
int main(int,char)
{
    // ===========================================================================================
    // You declare variables
    // ===========================================================================================
    // ===========================================================================================
    //      Following code declares variable and creates object at the same time
    // ===========================================================================================
    // c mtx: Mat type, (3,3), element in matrix is 32 bit float
    Mat mtx(3,3,CV_32F);
    // c cmtx: Mat type, (10,1), element in matrix is 64 bit float, 2 channel
    Mat cmtx(10,1,CV_64FC2);
    // c img: Size(5,3) doesn't mean (5,3) matrix 
    // but means length of width and height of image,
    // that is, mtx(4,3,CV_32F) means 4 row (length of height) and 3 column (length of width)
    // mtx(Size(4,3),CV_32F) means 4 width of image and 3 height of image
    // 8bit unsigned character, 3 channel
    // CV_8UC3 is main form for image processing
    Mat img(Size(5,3),CV_8UC3);

    // ===========================================================================================
    //      Following code declares variable first then creates object
    // ===========================================================================================
    Mat mtx2;
    mtx2=Mat(3,3,CV_32F);
    Mat cmtx2;
    cmtx2=Mat(10,1,CV_64FC2);

    // ===========================================================================================
    //      Following code creates object by using new keyword
    // ===========================================================================================
    Mat* mtx3=new Mat(3,3,CV_32F);
    // After processing on mtx3, you should delete mtx3 object in memory
    delete mtx3;

    // ===========================================================================================
    // setTo() is member method
    // ===========================================================================================
    // You set all elements by 10 in mtx object
    mtx.setTo(10);
    // You print value
    cout << mtx << endl;

    cmtx2.setTo(11);
    cout << cmtx2 << endl;

    return 0;
}
