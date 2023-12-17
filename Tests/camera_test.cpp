#include "camera.h"
#include <chrono>
#include <iostream>

int main(){
    // auto start = std::chrono::high_resolution_clock::now();
    camera Ca = camera();
    std::vector<std::vector<int>> matrix = Ca.cam_data(); 
    // // end timer
    // auto end = std::chrono::high_resolution_clock::now();
    // // print time elapsed
    // std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns\n";
    return 0;
}