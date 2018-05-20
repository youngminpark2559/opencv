// I note explanations from lecture by JH Kim 
// Lecture reference:
// https://www.youtube.com/playlist?list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// mouse event 
// 003_005.cpp
// https://www.youtube.com/watch?v=iWCqjWTx-wI&index=24&list=PLvX6vpRszMkye9Zj16aG9J063A9rBfBj2

// To accept mouse event, you should create callback function,
// which means you don't call callback function but system calls callback function
// And that means you should implement callback function for system to call callback function
// As system calls callback function, system pass value (event, xy coordinates, etc) in you
// Then, you should interpret those values (event) and process them

// =======================================================================
// Codes
// =======================================================================

// http://cvlecture.marearts.com/2016/12/opencv-lecture-3-5.html

// ...
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{   
    // You check if L button is clicked
    if (event == EVENT_LBUTTONDOWN)
    {
        // You print text and xy coordinates of mouse
        printf("lLBUTTONDOWN down %d, %d \n", x, y);

        // Since userdata is void pointer type, 
        // you cast it as Mat* ((Mat*)userdata), 
        // then you bring real data (*(Mat*)userdata)
        // Point(x, y) : current mouse location
        // 2: radius
        // color
        // thickness
        //circle( (*(Mat*)userdata), Point(x, y), 2, CV_RGB(255, 0, 0), 3);
    }
    else if (event == EVENT_RBUTTONDOWN)
    {
        printf("RBUTTONDOWN down %d, %d \n", x, y);
    }
    else if (event == EVENT_MBUTTONDOWN)
    {
        printf("MBUTTONDOWN down %d, %d \n", x, y);
    }
    else if (event == EVENT_MOUSEMOVE)
    {
        printf("move %d, %d \n", x, y);
    }
    
    // show dot from click
    imshow("img", (*(Mat*)userdata)); 
}

int main(int, char)
{
    namedWindow("img", 0);
    Mat img = imread("gh.jpg");
    
    // "img" : name of window where you get mouse event
    // CallBackFunc : callback function which system will return values via
    // &img : you pass Mat type variable's address, which will be taken by userdata in callback function
    setMouseCallback("img", CallBackFunc, &img);

    imshow("img", img); //show
    waitKey(0);

    
    // show dot from click
    // imshow("img", (*(Mat*)userdata)); 
    // Following code plays role of above code
    while (1)
    {
        imshow("img", img); //show
        if (waitKey(10) > 0)
        break;
    }

    destroyAllWindows();

    return 0;
}

// More example, cut area from video, which has mouse drag
// http://study.marearts.com/2015/03/to-save-mouse-drag-region-to-image-file.html
// More example, invert color from video, which has mouse drag
// http://study.marearts.com/2014/05/opencv-study-setmousecallback-function.html
