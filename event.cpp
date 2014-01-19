#include "event.h"

Event::Event(int _id, int _date, int _hour, string _message) : eventID(_id), date(_date), hour(_hour), message(_message)
{
}

Event::~Event()
{

}
