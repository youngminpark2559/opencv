// 000_build_001_prepare_environment.cpp
// https://www.youtube.com/watch?v=mCso6cwb2Ng&index=1&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2


// You will inspect how to build OpenCV (OpenCV 3.2 + CUDA + TBB)
// ===================================================================================
// 1. Environment
// ===================================================================================
// 1. 64bit
// 1. current setting version
// OpenCV 3.2
// Cuda Toolkit 8.0
// For build configuration
// CMake 3.8.0
// Library for CPU parallel processing
// TBB 2017

// ===================================================================================
// 2. Install libraries
// ===================================================================================
// @ cuda
// https://developer.nvidia.com/cuda-downloads
// @ tbb
// https://www.threadingbuildingblocks.org/
// download source code in github release
// @ opencv
// https://github.com/opencv/opencv
// download latest version source code
// * This is additional modules
// It's recommended when you build to also include this source code
// You can check out modules in docs.opencv.org/3.2.0
// https://github.com/opencv/opencv_contrib
// * Since you will be using OpenCV frequently, 
// create OpenCV_Library folder in C root directory
// Create 2 folders (build and source)
// Paste opencv_contrib-master, opencv-master, tbb2017_20170226oss folders into source folder
// @ CMake 
// https://cmake.org/
// * Go to download, download installer
// * Execute CMake
// * Select directory for "where is the source code" 
// to c:/OpenCV_Library/source/opencv-master/opencv-master
// to target CMakeLists file
// * Select directory for "where to build the binaries" 
// to c:/OpenCV_Library/build
// * Click Configure
// * Select compiler to build, for example, VS 14 2015 Win64
// then, cmake builds and configures source code to be fitted to your development environment
// * CMake automaticall finds and insert libraries when performing build
// However, if there is libraries which CMake couldn't find,
// you should manually find and insert them into build (check grouped and advanced)
// For example, go to "WITH", find WITH_TBB, check it
// Now, WITH_MATLAB is selected but when you didn't install matlab, 
// cmake can't find matlab, but ignoring absence, so you don't care about absence
// * When you run into error when including TBB,
// reference configuration as follow:
// * CMake Setting
// 1. TBB Setting
// * TBB_ENV_INCLUDE : 
// /tbb2017_20170226oss_win/tbb2017_20170226oss/include/
// * TBB_ENV_LIB : 
// /tbb2017_20170226oss_win/tbb2017_20170226oss/lib/intel64/vc14/tbb.lib
// * TBB_ENV_LIB_DEBUG : 
// /tbb2017_20170226oss_win/tbb2017_20170226oss/lib/intel64/vc14/tbb_debug.lib
// * TBB_VER_FILE : 
// /tbb2017_20170226oss_win/tbb2017_20170226oss/include/tbb_stddef.h
// * When finished manual file select, click configure
// opencv_world can create error, so, now, you're not checking it
// EXAMPLE takes longer time for build
// * You include extra opencv modules
// 1. OpenCV Cotrib Setting
// * OPENCV_EXTRA_MODUKES_PATH
// /opencv_contrib-master/opencv_contrib-master/modules
// opencv_world can create error, so, now, you're not checking it
// * In search box, find test
// Uncheck:
// BUILD_PERF_TESTS
// BUILD_TESTS
// because error can occur and they're not that related to building opencv
// click configure
// * Check entire summary for build
// Click Generate
// * See c:/OpenCV_Library/build
// * You can open project in 2 ways
// Click OpenCV in build forder or click Open project in CMake window
// Then, finally, you can see all the codes which were created based on your configurations via CMake
// In VS, go to CMakeTargets, go to ALL_BUILD, click "release build" to build entire source code to generate dll files
// Or, you can only specific project, for example, opencv_core project

// ===================================================================================
// 3. Step overview
// ===================================================================================
// Preparations : Install and download
// cmake
// cuda
// tbb
// opencv
// Run cmake
// Set configuration
// Code Generation
// Build by Visual Studio
// Build All
// Make dll, lib
// OpenCV DLL test
// VS Setting
// Sample Test

// ===================================================================================
// 4. reference
// ===================================================================================
// http://darkpgmr.tistory.com/102
