#ifndef MEETING_H
#define MEETING_H
#include "event.h"

class Meeting : public Event
{
    private:
        string placeOfMeeting;
        int durationOfMeeting;

    public:
        Meeting(int _id, QDateTime _dataIczas, string _message, string _place, int _duration);
        Meeting();

        virtual void printEventInfo();
        string getPlaceOfMeeting() const;
        void setPlaceOfMeeting(const string &value);
        int getDurationOfMeeting() const;
        void setDurationOfMeeting(int value);
};

#endif // MEETING_H
