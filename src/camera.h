#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

class camera
{
public:
    camera();
    ~camera();
    std::vector<std::vector<int>> cam_data();

private:

};

#include "camera.cpp"

#endif