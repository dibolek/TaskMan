#include "todolist.h"

ToDoList::ToDoList(int _id, int _date, int _hour, string _message) : Event(_id,_date,_hour,_message)
{
}

void ToDoList::printEventInfo()
{
        cout<< "(" << eventID << ") "
        << "Dnia " << date << ", o godzinie " << hour
        << "\n\tMasz do zrobienia: " << message
        <<endl;

}
