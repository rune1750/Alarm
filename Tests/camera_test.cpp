#include "camera.h"
#include <chrono>
#include <iostream>

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    camera Ca = camera();
    int matrix[9][9];
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            matrix[i][j] = Ca.cam_data();
            //std::cout << matrix[i][j]<< " ";
        }
        //std::cout<< '\n';
    }
    // end timer
    auto end = std::chrono::high_resolution_clock::now();
    // print time elapsed
        
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns\n";
    return 0;
}