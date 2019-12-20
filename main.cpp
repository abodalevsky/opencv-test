#include "config.h"
#include <iostream>

#include "lib/utility.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"

using namespace std;
using namespace cv;

void drawText(Mat &image);

int main()
{
  cout << "Open CV Test: " << OpenCV_Test_VERSION_MAJOR << "." << OpenCV_Test_VERSION_MINOR << endl;
  cout << "Open CV v: " << CV_VERSION << endl;

  // cout << "Call foo(2) returns: " << foo(2) << endl;

  Mat image;
  VideoCapture capture;
  capture.open(0);
  if (capture.isOpened())
  {
    cout << "Capture is opened" << endl;
    for (;;)
    {
      capture >> image;
      if (image.empty())
        break;
      drawText(image);
      imshow("Sample", image);
      if (waitKey(10) >= 0)
        break;
    }
  }
  else
  {
    cout << "No capture" << endl;
    image = Mat::zeros(480, 640, CV_8UC1);
    drawText(image);
    imshow("Sample", image);
    waitKey(0);
  }
}

void drawText(Mat &image)
{
  putText(image, "Hello OpenCV",
          Point(20, 50),
          FONT_HERSHEY_COMPLEX, 1, // font face and scale
          Scalar(255, 255, 255),   // white
          1, LINE_AA);             // line thickness and type
}
// CMake Build - F7
// CMake Run - Shift - F5