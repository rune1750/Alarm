#include <chrono>
#include <iostream>
#include <cstdlib>
#include <future>
#include <thread>
#include <vector>
#include <string>
#include "..\includes\alarm_system.h"
#include "..\includes\camera.h"
#include "..\includes\sensor.h"
#include "compute_detection.cpp"

alarm_system::alarm_system(sensor *sensor1, sensor *sensor2, camera *cam)
{
    s1 = *sensor1;
    s2 = *sensor2;
    C = *cam;
}

alarm_system::~alarm_system()
{
}

void alarm_system::start_system()
{
label:

    if (system_state == "inactive")
    {
        while (system_state == "inactive")
        {
            if (valid(p))
            {
                p = 7;
                event_handler(0);
                goto label;
            }
            std::cout << "Invalid pin" << std::endl;
        }
    }

    if (system_state == "active")
    {
        while (system_state == "active")
        {
            // thread sensors and camera
            std::promise<int> p1;
            std::promise<int> p2;
            std::promise<std::vector<std::vector<int>>> p3;

            std::future<int> f1 = p1.get_future();
            std::future<int> f2 = p2.get_future();
            std::future<std::vector<std::vector<int>>> f3 = p3.get_future();

            std::thread t3(&camera::cam_data, &C, std::move(p3));
            std::thread t1(&sensor::sens_data, &s1, std::move(p1), 3);
            std::thread t2(&sensor::sens_data, &s2, std::move(p2), 16);

            t1.join();
            t2.join();
            t3.join();

            int s1_data = f1.get();
            int s2_data = f2.get();
            std::vector<std::vector<int>> matrix = f3.get();
            
            if (compute_detection(matrix, s1_data, s2_data))
            {
                event_handler(2);
                goto label;
            }
            
        }
    }

    if (system_state == "alarmed")
    {
        std::cout << "Enter pin or wait 10 seconds to disable alarm" << std::endl;
        // start a 10 second timer. If a correct pin is entered meanwhile, go to active state.
        //  if the timer runs out, go to active state aswell
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        while (system_state == "alarmed")
        {
            if (valid(p))
            {
                p = 7;
                event_handler(0);
                goto label;
            }
            end = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() >= 10)
            {
                system_state = "active";
                goto label;
            }
        }
    }

    goto label;
}

// return random integer between 0 and 9
void alarm_system::pin()
{
    srand(time(NULL));
    p = rand() % 10;
}

// Function for killing the system
void alarm_system::kill()
{
    event_handler(1);
    std::cout << "KILLING SYSTEM" << std::endl;
}

bool alarm_system::valid(int p)
{
    return p % 2 == 0;
}

bool alarm_system::compute_detection(std::vector<std::vector<int>> matrix, int s1_data, int s2_data)
{
    return Compute_Detection(matrix, s1_data, s2_data);
}

// Event handler to ensure that every event is handled correctly
// This function is called by the main function
// event_number is an integer between 0 and 2
// 0: activate system (by entering pin)
// 1: deactivate system (exiting system)
// 2: check for intrusions
void alarm_system::event_handler(int event_number)
{
    int t;
    if (system_state == "inactive")
    {
        t = 0;
    }
    else if (system_state == "active")
    {
        t = 1;
    }
    else if (system_state == "alarmed")
    {
        t = 2;
    }
    // If system_state is not valid, then throw an error
    else
    {
        std::cout << "Error: system_state is not valid" << std::endl;
    }

    switch (t)
    {
    case 0:
        // Check if pin is valid
        if (event_number == 0)
        {
            std::cout << "pin is valid" << std::endl;
            system_state = "active";
        }
        // Check if system is already inactive
        else if (event_number == 1)
        {
            std::cout << "System is already inactive" << std::endl;
        }
        // If system is inactive, then there is no need to check for intrusions
        else if (event_number == 2)
        {
            std::cout << "Activate the system to check for intrusions" << std::endl;
        }
        // If event_number is not valid, then throw an error
        else
        {
            std::cout << "Error: event_number is not valid" << std::endl;
        }
        break;

    case 1:
        // System is already valid
        if (event_number == 0)
        {
            std::cout << "System is already active" << std::endl;
        }
        // Deactivate system
        else if (event_number == 1)
        {
            std::cout << "System is now inactive" << std::endl;
            system_state = "inactive";
        }
        // Intrusion detected
        else if (event_number == 2)
        {
            std::cout << "Intrusion detected" << std::endl;
            system_state = "alarmed";
        }
        // If event_number is not valid, then throw an error
        else
        {
            std::cout << "Error: event_number is not valid" << std::endl;
        }

        break;

    case 2:
        // If pin is valid then return to active state
        if (event_number == 0)
        {
            std::cout << "Valid pin, returning to active state" << std::endl;
        }
        // Kill the system
        else if (event_number == 1)
        {
            std::cout << "System is now inactive" << std::endl;
            system_state = "inactive";
        }
        // System is already alarmed, so it cannot be alarmed again
        else if (event_number == 2)
        {
            std::cout << "System is already alarmed" << std::endl;
        }
        // If event_number is not valid, then throw an error
        else
        {
            std::cout << "Error: event_number is not valid" << std::endl;
        }
        break;

    default:
        std::cout << "Error: System failing" << std::endl;
        break;
    }
}