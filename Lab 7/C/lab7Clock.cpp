// File lab7Clock.cpp
// ENSF 337  LAB 7 - EXERCISE C
// By: Quentin Jennings

#include "lab7Clock.h"

//constructors
Clock::Clock(): hour(0), minute(0), second(0) {}
Clock::Clock(int s): hour(0), minute(0), second(0)
{
    if(s > 0)
        sec_to_hms(s);
}
Clock::Clock(int h, int m, int s): hour(h), minute(m), second(s)
{
    if(hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
}

//private functions
void Clock::sec_to_hms(int s)
{
    hour = 0;
    minute = 0;
    second = s;

    while(second > 59)
    {
        second -= 60;
        minute++;
    }
    while(minute > 59)
    {
        minute -= 60;
        hour++;
    }
    while(hour > 23)
    {
        hour -= 24;
    }
}
int Clock::hms_to_sec()
{
    return second + 60*minute + 3600*hour;
}

//public functions
int Clock::get_hour()const {return hour;}
int Clock::get_minute()const {return minute;}
int Clock::get_second()const {return second;}

void Clock::set_hour(int h)
{
    if(h >= 0 && h <= 23)
        hour = h;
}
void Clock::set_minute(int m)
{
    if(m >= 0 && m <= 59)
        minute = m;
}
void Clock::set_second(int s)
{
    if(s >= 0 && s <= 59)
        second = s;
}

void Clock::increment()
{
    second++;
    sec_to_hms(hms_to_sec());
}
void Clock::decrement()
{
    if(hms_to_sec() == 0)
    {
        hour = 23;
        minute = 59;
        second = 59;
    }
    else
    {
        second--;
        sec_to_hms(hms_to_sec());
    }
}
void Clock::add_seconds(int s)
{
    sec_to_hms(hms_to_sec() + s);
}
