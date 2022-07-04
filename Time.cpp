#include "Time.hpp"

static time_t Time::milliseconds()
    {
        struct timeval time_now
        {
        };
        gettimeofday(&time_now, nullptr);
        time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        return msecs_time;
    }