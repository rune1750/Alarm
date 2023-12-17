#include "includes\sensor.h"
#include "includes\camera.h"
#include "includes\alarm_system.h"
#include <iostream>
#include <cstdlib>
#include <chrono>

int main()
{
    // Create sensor and camera objects
    sensor s1;
    sensor s2;
    camera C;

    // Create alarm system object
    alarm_system A(&s1, &s2, &C);
    
    A.pin();
    A.pin();
    A.pin();
    A.pin();
    A.pin();
    
    // start system
    A.start_system();



    while(1){
        int i = 0;
        i++;
    }

    return 0;
}