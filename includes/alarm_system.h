#ifndef ALARM_SYSTEM_H
#define ALARM_SYSTEM_H

#include <future>
#include <thread>
#include <vector>
#include <string>

class alarm_system
{
public:
    alarm_system(sensor *s1, sensor *s2, camera *C);
    ~alarm_system();
    void start_system();
    void kill();
    void pin();
    int p = 1;

private:
    void event_handler(int event_number);
    bool valid(int p);
    bool compute_detection(std::vector<std::vector<int>> cam_data, int s1_data, int s2_data);
    sensor s1;
    sensor s2;
    camera C;
    std::string system_state = "inactive";
};

#include "..\src\alarm_system.cpp"

#endif
