// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// linear algebra operations(solver for inhomogeneous equation,eigenvalue,eigenvector,SVD) with opencv
// 002_008.cpp
// https://www.youtube.com/watch?v=Kw-t2eJVnKs&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2&index=18

// =======================================================================
// solver (methods) for inhomogeneous equation (system)
// =======================================================================

// c dm2 : A
double dm2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
Mat A(3,3,CV_64FC1,dm2);
Mat x(3,1,CV_64FC1);

// c vvb[] : b
double vvb[]={14,32,52};
Mat b(3,1,CV_64FC1,vvb);

// This solves Ax=b in respect to x
// c DECOMP_SVD : option, decomposition svd
cv::solve(A,b,x,DECOMP_SVD);

// x : found x
cout<<x<<endl;

// check by comparing result to b
cout<<A*x<<endl;

// =======================================================================
// eigen analysis, eigenvector, eigenvalue
// =======================================================================

// eigen analysis of symmetrical matrix
// c f11[] : source for matrix
float f11[]={1,0.446,-0.56,0.446,1,-0.239,-0.56,0.239,1};
// c data : (3,3) matrix created from f11[]
Mat data(3,3,CV_32F,f11);
Mat value,vector;
// c data : source matrix
// value : calculated eigenvalue
// vector : calculated eigenvector
eigen(data,value,vector);
cout<<"eigenvalues"<<value<<endl;
cout<<"eigenvectors"<<endl;
cout<<vector<<endl;

// You prove if result is right by checking following formular is correct
// AV=vV
cout<<vector<<endl;
cout<<endl<<"AV"<<endl;
cout<<data+vector<<endl;

cout<<"vV"<<endl;
// c ValueEye : (3,3) identity matrix
Mat ValueEye=Mat::eye(3,3,CV_32F);
// You insert each eigenvalue into ValueEye
// img 2018-05-19 13-45-50.png
ValueEye.at<float>(0,0)=value.at<float>(0,0);
ValueEye.at<float>(0,0)=value.at<float>(0,0);
ValueEye.at<float>(0,0)=value.at<float>(0,0);
cout<<vector+ValueEye<<endl;

// =======================================================================
// singular value decomposition : SVD (특이값 해)
// =======================================================================

// SVD is very useful technique when decompositioning

float f11[]={1,0.446,-0.56,0.446,1,-0.239,-0.56,0.239,1};
Mat data(3,3,CV_32F,f11);

Mat w,u,v;
// SVDecomp devides data matrix into 3 matrices (w,u,v)
// satisfying $$$A=UWV^{T}$$$
// But unique characteristic of A will be inserted into u, w, v
SVDecomp(data,w,u,v);
