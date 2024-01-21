#include <vector>
#include <iostream>

bool Compute_Detection(std::vector<std::vector<int>> matrix, int s1_data, int s2_data)
{
    // auto start = std::chrono::high_resolution_clock::now();
    // compute using vector
    std::vector<std::vector<int>> new_matrix;
    for (int i = 0; i < 9; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < 9; j++)
        {
            row.push_back(matrix[i][j] * (s1_data + s2_data));
        }
        new_matrix.push_back(row);
    }

    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sum += new_matrix[i][j];
        }
    }
    std::cout << "sum: " << sum << std::endl;
    // std::cout << "sensor: " << s1_data + s2_data << std::endl;
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[i].size(); j++)
    //     {
    //         std::cout << matrix[i][j]<< " ";
    //     }
    //     std::cout << std::endl;
    // }
    // auto end = std::chrono::high_resolution_clock::now();
    // std::cout << "time elapsed: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<< std::endl;
    return sum * 2 >= 6290;
}