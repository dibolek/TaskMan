#ifndef EVENT_H
#define EVENT_H
#include "functions.h"
#include <iostream>

using namespace std;

class Event
{
    protected:
        int eventID;
        int date;
        int hour;
        string message;

    public:
        Event(int _id, int _date, int _hour, string _message);
        virtual ~Event();

        virtual void printEventInfo()=0;
};

#endif // EVENT_H
