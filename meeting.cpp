#include "meeting.h"

Meeting::Meeting(int _id, int _date, int _hour, string _message, string _place, int _duration) : Event(_id,_date,_hour,_message), placeOfMeeting(_place), durationOfMeeting(_duration)
{
}

void Meeting::printEventInfo()
{
    cout<< "(" << eventID << ") "
        << "Masz spotkanie w "<< placeOfMeeting << ", dnia " << date
        << ", o godzinie " << hour << ", ktore trwac bedzie "
        << durationOfMeeting << " godzin(y).\n\tDodatkowe informacje: " << message
        <<endl;
}

