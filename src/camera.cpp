#include "..\includes\camera.h"
#include <chrono>
#include <cstdlib>
#include <thread>
#include <vector>

camera::camera()
{
}

camera::~camera()
{
}

// return a 9*9 matrix of random integers between 0 and 9
std::vector<std::vector<int>> camera::cam_data()
{
    srand(time(NULL));
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < 9; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < 9; j++)
        {
            row.push_back(rand() % 10);
        }
        matrix.push_back(row);
    }
    return matrix; 
}