#include "camera.h"
#include <cstdlib>


camera::camera()
{
}

camera::~camera()
{
}

// return a 9*9 matrix of random integers between 0 and 9
int camera::cam_data()
{
    int matrix[9][9];
    cam_data_label1:for(int i=0; i<9; i++)
    {
        cam_data_label0:for(int j=0; j<9; j++)
        {
            matrix[i][j] = xorshf96() % 10;
            //std::cout << matrix[i][j]<< " ";
        }
        //std::cout<< '\n';
    }
    
    return matrix[8][8];
}
