#include "config.h"
#include <iostream>

#include "lib/utility.h"

using namespace std;

int main() {
  cout << "Open CV Test: " << OpenCV_Test_VERSION_MAJOR << "." << OpenCV_Test_VERSION_MINOR << endl;

  cout << "Call foo(2) returns: " << foo(2) << endl;
}

// CMake Build - F7
// CMake Run - Shift - F5