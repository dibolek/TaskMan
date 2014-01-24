#ifndef CALENDAR_H
#define CALENDAR_H
#include <date.h>
#include <cstring>
#include <iomanip>

using namespace std;

class Calendar
{
private:

public:
    Calendar();

    void displayCalendar(Date &data);
};

#endif // CALENDAR_H
