#pragma once

#include <chrono>
#include <sys/time.h>
#include <time.h>

class Time                                                                                              //prende time in milliseconds 
{
public:
    static time_t milliseconds();              // static 
};