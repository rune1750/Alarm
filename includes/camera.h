#ifndef CAMERA_H
#define CAMERA_H

#include <future>
#include <vector>

class camera
{
public:
    camera();
    ~camera();
    void cam_data(std::promise<std::vector<std::vector<int>>> &&p);

private:

};

#include "..\src\camera.cpp"

#endif