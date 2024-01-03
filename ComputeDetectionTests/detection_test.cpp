#include <chrono>
#include <iostream>
#include "camera.h"
#include "sensor.h"

// Compute and identify detection
int main()
{   
    sensor s1;;
    sensor s2;
    
    int s1_data, s2_data;

    camera Ca;

    auto start = std::chrono::high_resolution_clock::now();
    int matrix[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matrix[i][j] = Ca.cam_data();
            // std::cout << matrix[i][j]<< " ";
        }
        // std::cout<< '\n';
    }

    int new_matrix[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            new_matrix[i][j] = (matrix[i][j] * (s1_data + s2_data));
        }
    }

    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sum += new_matrix[i][j];
        }
    }

    // end timer
    auto end = std::chrono::high_resolution_clock::now();
    // print time elapsed
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns\n";

    std::cout << "sum: " << sum << std::endl;
    std::cout << "Intrusion? " << (sum >= 6290) << std::endl;

    return 0;
}