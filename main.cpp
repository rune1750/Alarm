#include "src\sensor.h"
#include "src\camera.h"
#include "src\alarm_system.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
// #include "camera_test.cpp"

int main()
{
    //Create sensor and camera objects
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


    return 0;
}