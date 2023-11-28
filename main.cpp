#include "includes\sensor.h"
#include "includes\camera.h"
#include "includes\alarm_system.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

int main()
{
    // Create sensor and camera objects
    sensor s1;
    sensor s2;
    camera C;

    // Create alarm system object
    alarm_system A(&s1, &s2, &C);

    // start system
    std::thread one(&alarm_system::start_system, &A);

    A.start_system();
    A.pin();
    A.pin();
    A.pin();
    A.pin();
    A.pin();

    return 0;
}