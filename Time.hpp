//file che si occupa del tempo
#pragma once
#include <chrono>
#include <sys/time.h>
#include <time.h>

class Time                                                                                              //prende time in milliseconds 
{
public:
    static time_t milliseconds()
    {
        struct timeval time_now;
        {
        };
        gettimeofday(&time_now, nullptr);
        time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        return msecs_time;
    }
};