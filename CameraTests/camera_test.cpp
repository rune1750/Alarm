#include "camera.h"
#include <chrono>
#include <iostream>

int main(){
    camera C;
    int dim = 9;
    auto start = std::chrono::high_resolution_clock::now();
    int** matrix = C.cam_data(dim);
    // end timer
    auto end = std::chrono::high_resolution_clock::now();
    // print time elapsed
        
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns\n";
    return 0;
}
