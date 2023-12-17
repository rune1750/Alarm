#ifndef CAMERA_H
#define CAMERA_H

#include <future>
#include <vector>

class camera
{
public:
    camera();
    ~camera();
    std::vector<std::vector<int>> cam_data();

private:

};

#include "..\src\camera.cpp"

#endif