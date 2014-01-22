#include "todolist.h"

ToDoList::ToDoList(int _id, QDateTime _dataIczas, string _message) : Event(_id,_dataIczas,_message)
{
}

ToDoList::ToDoList()
{
    
}

void ToDoList::printEventInfo()
{
        cout<< "(" << eventID << ") "
        << "Dnia " << dataIczas.toString("dd-MM-yyyy', o godzinie 'hh:mm").toStdString()
        << "\n\tMasz do zrobienia: " << message
        <<endl;

}
