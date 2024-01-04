#include "camera.h"
#include <chrono>
#include <iostream>

int main(){
    camera C;
    int dim = 9;
    auto start = std::chrono::high_resolution_clock::now();
    int* matrix = C.cam_data(dim);
    // end timer
    auto end = std::chrono::high_resolution_clock::now();
    // print time elapsed
    int matrix1[9][9];
    for(int i=0; i<dim; i++)
    {
        for(int j=0; j<dim; j++)
        {
            matrix1[i][j] = *matrix;
            matrix++;

        }

    }    
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns\n";
    return 0;
}

