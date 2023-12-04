#ifndef SENSOR_H
#define SENSOR_H

#include <future>

class sensor
{
public:
    sensor();
    ~sensor();
    void sens_data(std::promise<int> &&p, int i);

private:
};

#include "..\src\sensor.cpp"

#endif