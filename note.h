#ifndef NOTE_H
#define NOTE_H
#include "event.h"

class Note : public Event
{
    public:
        Note(int _id, QDateTime _dataIczas, string _message);
        Note();

        virtual void printEventInfo();
};

#endif // NOTE_H
