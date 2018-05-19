// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// matrix operation with Mat class
// 002_007.cpp
// https://www.youtube.com/watch?v=oxrZr4kEvP8&index=17&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// =======================================================================
// vector product
// =======================================================================

// vector means matrix which has 1 column, multiple rows
double va[]={1,2,3};
double vb[]={0,0,1};
double vc[3];

Mat Va(3,1,CV_64FC1,va);
Mat Vb(3,1,CV_64FC1,vb);
Mat Vc(3,1,CV_64FC1,vc);

// there are 2 ways of multiply vector: 
// inner product (dot product)
double res=Va.dot(Vb);
// outer product (cross product)
Vc=Va.cross(Vb);
cout<<res<<" "<<Vc<<endl;

// =======================================================================
// operation on single matrix
// =======================================================================

// You transpose Mb matrix
Mc=Mb.t();
cout<<Mc<<endl;

// You sum all element located in diagonal positions
cv::Scalar t=trace(Ma);
cout<<t.val[0]<<endl;

// You can find determinant of matrix
double d=determinant(Ma);
cout<<d<<endl;

// You can find inverse of matrix
Mc d=Ma.inv();
invert(Ma,Mc);
cout<<Mc<<endl;
