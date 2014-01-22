#include "meeting.h"


string Meeting::getPlaceOfMeeting() const
{
    return placeOfMeeting;
}

void Meeting::setPlaceOfMeeting(const string &value)
{
    placeOfMeeting = value;
}

int Meeting::getDurationOfMeeting() const
{
    return durationOfMeeting;
}

void Meeting::setDurationOfMeeting(int value)
{
    durationOfMeeting = value;
}
Meeting::Meeting(int _id, QDateTime _dataIczas, string _message, string _place, int _duration) : Event(_id,_dataIczas,_message), placeOfMeeting(_place), durationOfMeeting(_duration)
{
}

Meeting::Meeting()
{
    
}

void Meeting::printEventInfo()
{
    cout<< "(" << eventID << ") "
        << "Masz spotkanie w "<< placeOfMeeting << ", dnia "
        << dataIczas.toString("dd-MM-yyyy', o godzinie 'hh:mm").toStdString()
        << ", ktore trwac bedzie " << durationOfMeeting
        << " godzin(y).\n\tDodatkowe informacje: " << message <<endl;
}

