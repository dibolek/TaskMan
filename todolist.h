#ifndef TODOLIST_H
#define TODOLIST_H
#include "event.h"

class ToDoList : public Event
{
    public:
        ToDoList(int _id, QDateTime _dataIczas, string _message);

        virtual void printEventInfo();
};

#endif // TODOLIST_H
