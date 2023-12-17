#ifndef ALARM_SYSTEM_H
#define ALARM_SYSTEM_H


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

private:
    void event_handler(int event_number);
    bool valid(int p); 
    bool compute_detection(std::vector<std::vector<int>> matrix, int s1_data, int s2_data);
    sensor s1;
    sensor s2;
    camera C;
    std::string system_state = "inactive";
    int p;
};

#include "alarm_system.cpp"

#endif
