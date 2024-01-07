#include "camera.h"
#include <cstdlib>


camera::camera()
{
}

camera::~camera()
{
}

int camera::cam_data()
{
    int matrix[9][9];
    cam_data_label1:for(int i=0; i<9; i++)
    {
        cam_data_label0:for(int j=0; j<9; j++)
        {
            matrix[i][j] = xorshf96() % 10;
        }
    }

    return matrix[8][8];
}
