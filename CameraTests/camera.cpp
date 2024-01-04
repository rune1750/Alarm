#include "camera.h"
#include <cstdlib>


camera::camera()
{
}

camera::~camera()
{
}

// return a 9*9 matrix of random integers between 0 and 9
int** camera::cam_data(int dim)
{      
    
    int** matrix = new int*[dim];
    for(int i=0; i<dim; i++)
    {
        matrix[i] = new int[dim];
        for(int j=0; j<dim; j++)
        {
            matrix[i][j] = 47 % 10;
            //std::cout << matrix[i][j]<< " ";
        }
        //std::cout<< '\n';
    }
    
    return matrix;
}