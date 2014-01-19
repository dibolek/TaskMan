#ifndef TODOLIST_H
#define TODOLIST_H
#include "event.h"

class ToDoList : public Event
{
    public:
        ToDoList(int _id, int _date, int _hour, string _message);

        virtual void printEventInfo();
};

#endif // TODOLIST_H
