#include "camera.h"
#include <cstdlib>


camera::camera()
{
}

camera::~camera()
{
}

// return a 9*9 matrix of random integers between 0 and 9
int* camera::cam_data(int dim)
{      
    int matrix[9*9];
    for(int i=0; i<dim; i++)
    {
        for(int j=0; j<dim; j++)
        {
            matrix[ dim * i + j ] = xorshf96() % 10;

        }

    }
    int* point = &matrix[0];
    
    return point;
}