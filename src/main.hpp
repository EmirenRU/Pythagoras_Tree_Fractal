#include <iostream>
#include <cmath>

#include "GLFW/glfw3.h"
#include <GL/gl.h>
#include <GL/glx.h>

using namespace std;

#define pi 3.1415926535897932384626433832795

// #define ORIGINAL

#ifndef ORIGINAL
#define ANTIALIASING
#endif // ANTIALIASING

#ifndef ANTIALIASING
#define ORIGINAL 
#endif // ORIGINAL