#include "camera.h"
#include <iostream>

int main(){
    camera C;
    int matrix[9][9];
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            matrix[i][j] = C.cam_data();
        }
    }
    return 0;
}
