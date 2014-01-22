#include "note.h"

Note::Note(int _id, QDateTime _dataIczas, string _message) : Event(_id,_dataIczas,_message)
{
}

void Note::printEventInfo()
{
        cout<< "(" << eventID << ") "
            << "Notatka dodana dnia "
            <<  dataIczas.toString("dd-MM-yyyy' o godzinie 'hh:mm").toStdString()
            << "\n\tTresc: " << message <<endl;

}
