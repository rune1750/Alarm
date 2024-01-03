#include "camera.h"
#include <cstdlib>
camera::camera()
{
}

camera::~camera()
{
}

// return a 9*9 matrix of random integers between 0 and 9
long camera::cam_data()
{
    return xorshf96() % 10;
}