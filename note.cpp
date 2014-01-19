#include "note.h"

Note::Note(int _id, int _date, int _hour, string _message) : Event(_id,_date,_hour,_message)
{
}

void Note::printEventInfo()
{
        cout<< "(" << eventID << ") "
        << "Notatka dodana dnia " << date
        << ", o godzinie " << hour
        << "\n\tTresc: " << message
        <<endl;

}
