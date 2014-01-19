#ifndef NOTE_H
#define NOTE_H
#include "event.h"


class Note : public Event
{
    public:
        Note(int _id, int _date, int _hour, string _message);

        virtual void printEventInfo();
};

#endif // NOTE_H
