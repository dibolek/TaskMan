#include "event.h"

int Event::getEventID() const
{
    return eventID;
}

void Event::setEventID(int value)
{
    eventID = value;
}

string Event::getMessage() const
{
    return message;
}

void Event::setMessage(const string &value)
{
    message = value;
}

QDateTime Event::getDataIczas() const
{
    return dataIczas;
}

void Event::setDataIczas(const QDateTime &value)
{
    dataIczas = value;
}
Event::Event(int _id, QDateTime _dataIczas, string _message) : eventID(_id), dataIczas(_dataIczas), message(_message)
{
}

Event::Event()
{
    
}

Event::~Event()
{

}
