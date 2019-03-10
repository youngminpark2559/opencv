// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// deal with Mat with cpu and gpu
// 002_009.cpp
// https://www.youtube.com/watch?v=qHGF6IaYgNE&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// =======================================================================
// Concepts
// =======================================================================
// gpgpu : general purpose gpu
    // nvidia cuda
    // amd opencl


// =======================================================================
// Codes
// =======================================================================

Window function GetTickCount, OpenCV function getTickCount (example source code)
Do not confuse,
GetTickCount and getTickCount is different function.
The first is ms window function.
The second is openCV function.
The method to use is little bit different.
Show example source code~!
-----------------------
unsigned long Atime=0, Btime=0;
unsigned long AAtime=0, BBtime=0;

Atime = GetTickCount();
AAtime = getTickCount();

someFunctionTakeLongTime(); //Test function

Btime = GetTickCount();
BBtime = getTickCount();

printf("%.2lf \n",  (Btime - Atime)/1000.0 );
printf("%.2lf \n",  (BBtime - AAtime)/getTickFrequency() );
-----------------------
Be careful when you use this function.

// =======================================================================
//      Gpu Mat, Cpu Mat example code 1
// =======================================================================

// c gpuImg : GpuMat type variable
cuda::GpuMat gpuImg;
// c img : Mat type, ss.jpg
Mat img = imread("ss.jpg");
unsigned long AAtime = 0, BBtime = 0;
AAtime = getTickCount();

// =======================================================================
// gpu environment
// =======================================================================
// You upload "ordinary Mat img" to "gpuMat gpuImg",
// which means you upload contents located in cpu memory into gpu memory
gpuImg.upload(img);
vector<cuda::GpuMat> rgbGpuMat(3);
// You perfrom split processing with cuda
cuda::split(gpuImg, rgbGpuMat); 
Mat r, g, b;

// After processing on gpu, you should download contents into gpu memory

// Note that uploading contents from cpu memory into gpu memory,
// downloading contents from gpu memory into cpu memory, takes time,
// even if gpu processing is fast
rgbGpuMat[0].download(b);
rgbGpuMat[1].download(g);
rgbGpuMat[2].download(r);

// =======================================================================
// cpu environment
// =======================================================================

BBtime = getTickCount();
printf("gpu : %.2lf second \n", (BBtime - AAtime) / getTickFrequency());

vector<mat> rgbMat(3);

// cuda processing
split(img, rgbMat);

// Mat r, g, b;
// download
b = rgbMat[0]; 
g = rgbMat[1];
r = rgbMat[2];
BBtime = getTickCount();
printf("cpu : %.2lf second \n", (BBtime - AAtime) / getTickFrequency());

namedWindow("r", 0); //make window
imshow("r", r); //show
namedWindow("g", 0); //make window
imshow("g", g); //show
namedWindow("b", 0); //make window
imshow("b", b); //show
waitKey(0);

// =======================================================================
//     Gpu Mat, Cpu Mat example 2
// =======================================================================

unsigned long AAtime = 0, BBtime = 0;
cuda::GpuMat gpuImg, gpuImg_out;
Mat img, img_out, img_out2;
img = imread("2mb.jpg");
gpuImg.upload(img);
AAtime = getTickCount();
cuda::bitwise_not(gpuImg, gpuImg_out);
Ptr<cv::cuda::filter> filter = cuda::createSobelFilter(img.type(), img.type(), 1, 0);
filter->apply(gpuImg_out, gpuImg_out);
BBtime = getTickCount();
gpuImg_out.download(img_out);
printf("gpu : %.2lf second \n", (BBtime - AAtime) / getTickFrequency());
AAtime = getTickCount();
bitwise_not(img, img_out2);
Sobel(img_out2, img_out2, img_out2.depth(), 1, 0);
BBtime = getTickCount();
printf("cpu : %.2lf second \n", (BBtime - AAtime) / getTickFrequency());
imshow("cpu_img", img_out);
imshow("cpu_img", img_out2);
waitKey(0);

