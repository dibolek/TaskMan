#include "note.h"

Note::Note(int _id, QDateTime _dataIczas, string _message) : Event(_id,_dataIczas,_message)
{
}

Note::Note()
{
    
}

void Note::printEventInfo()
{
        cout<< "( Notatka ) "
            << "  Dodana dnia "
            <<  dataIczas.toString("dd-MM-yyyy' o godzinie 'hh:mm").toStdString()
            << ",\n                 Tresc: " << message <<endl;

}
