#ifndef EVENT_H
#define EVENT_H
#include "functions.h"
#include <iostream>
#include <QDateTime>
#include <date.h>

using namespace std;

class Event
{
    protected:
        int eventID;
        QDateTime dataIczas;
        string message;

    public:
        Event(int _id, QDateTime _dataIczas, string _message);
        Event();
        virtual ~Event();

        virtual void printEventInfo()=0;
        int getEventID() const;
        void setEventID(int value);
        string getMessage() const;
        void setMessage(const string &value);
        QDateTime getDataIczas() const;
        void setDataIczas(const QDateTime &value);
};

#endif // EVENT_H
