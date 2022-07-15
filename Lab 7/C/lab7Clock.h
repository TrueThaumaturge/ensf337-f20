// File lab7Clock.h
// ENSF 337  LAB 7 - EXERCISE C
// By: Quentin Jennings

#ifndef LAB7CLOCK
#define LAB7CLOCK

class Clock{
private:
    int hour, minute, second;
    int hms_to_sec();
    void sec_to_hms(int s);


public:
    Clock();
    Clock(int s);
    Clock(int h, int m, int s);

    int get_hour()const;
    int get_minute()const;
    int get_second()const;

    void set_hour(int h);
    void set_minute(int m);
    void set_second(int s);

    void increment();
    void decrement();
    void add_seconds(int s);
};

#endif
