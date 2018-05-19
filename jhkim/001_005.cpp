// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// 001_Introduce_005_basic_operation_on_Mat.cpp
// https://www.youtube.com/watch?v=nyd9sB9ZdUY&index=8&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

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
#include "opencv2/opencv.hpp"

using namespace cs;
using namespace std;

int main(int,char)
{   
    // c m: Mat type variable, (3,3) matrix initialized by 1
    Mat m=Mat::ones(3,3,CV_64F);
    m=m*3;
    cout<<m<<endl;

    Mat m_z=Mat::zeros(3,3,CV_64F);
    m_z=m_z*3;
    cout<<m_z<<endl;
    
    // Note that m2 references dm array,
    // which means if you change m2, dm is also changed vice versa
    // c dm: (2,2) shape 2 d array
    double dm[3][3]={{1,2,1},{0,1,1},{1,0,0}};
    // c m2: (3,3) shape matrix intialized by dm array
    Mat m2=Mat(3,3,CV_64F,dm);
    cout<<m2<<endl;
    
    // =======================================================================
    // arithmetics with matrix
    // =======================================================================
    cout<<m+m2<<endl<<endl;
    cout<<m-m2<<endl<<endl;
    // Note that this is matrix multiplication (dot product)
    cout<<m*m2<<endl<<endl;
    // Note that this is element wise multiplication
    cout<<m.mul(m2)<<endl<<endl;
    cout<<m/m2<<endl<<endl;

    // =======================================================================
    // inverse
    // =======================================================================
    cout<<m2.inv()<<endl;

    // =======================================================================
    // transpose
    // =======================================================================
    cout<<m2.t()<<endl;

    // =======================================================================
    // reference affects
    // =======================================================================
    m2=m+m2
    cout<<m2<<endl<<endl;

    // This prints dm array
    for (int i=0;i<3;++i)
    {
        for (int i=0;i<3;++i)
            cout<<dm[i][j]<<" ";
        cout<<endl;
    }

    // This changes value of dm
    dm[2][2]=1000;
    cout<<m2<<endl<<endl;

    return 0;
}
