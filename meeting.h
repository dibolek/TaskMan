#ifndef MEETING_H
#define MEETING_H
#include "event.h"

class Meeting : public Event
{
    private:
        string placeOfMeeting;
        int durationOfMeeting;

    public:
        Meeting(int _id, int _date, int _hour, string _message, string _place, int _duration);

        virtual void printEventInfo();
};

#endif // MEETING_H
