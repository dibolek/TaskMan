#include "user.h"


//--------------constructors and destructor section ----------------------------

User::User(string name, int id, string fname)
{
    userName = name;
    userID = id;
    fileName = fname;
}

User::User()
{
    userName = "Unknown";
    userID = 0;
    fileName = "unknown.txt";
}

User::~User()
{
    while (! eventsVector.empty()) {
            delete eventsVector.back();
            eventsVector.pop_back();
        }
}

//--------------------- get and set section ------------------------------------

vector<Event *> User::getEventsVector() const
{
    return eventsVector;
}

int User::getUserID() const
{
    return userID;
}

void User::setUserID(int value)
{
    userID = value;
}

string User::getUserName() const
{
    return userName;
}

void User::setUserName(const string &value)
{
    userName = value;
}

string User::getFileName() const
{
    return fileName;
}

void User::setFileName(const string &value)
{
    fileName = value;
}

//---------------------- other methods -----------------------------------------

void User::addEvent(int typeOfEvent, int id, QDateTime _dataIczas, string message, string place, int duration)
{
    Event * eventTMP = 0;

    switch (typeOfEvent) {
        case 1:
            eventTMP = new Meeting(id,_dataIczas,message,place,duration);
            break;
        case 2:
            eventTMP = new ToDoList(id,_dataIczas,message);
            break;
        case 3:
            eventTMP = new Note(id,_dataIczas,message);
            break;
        default:
            break;
        }

    eventsVector.push_back(eventTMP);
}

void User::removeEvent()
{

}

int User::getEventsCount()
{
    return static_cast<int>( eventsVector.size() );
}

int User::whatTypeEventIs(Event *p_Event)
{
    Meeting *p_Meeting = 0;
    ToDoList *p_ToDoList = 0;
    Note *p_Note = 0;

    if ( ( p_Meeting = dynamic_cast<Meeting*>(p_Event) ) )
        return 1; // 1- meeting
    if ( ( p_ToDoList = dynamic_cast<ToDoList*>(p_Event) ) )
        return 2; // 2- todolist
    if ( ( p_Note = dynamic_cast<Note*>(p_Event) ) )
        return 3; // 3- note
    return 4 ;  // 4 - event
}

void User::sortEvents()
{

}

void User::displayEvents()
{
    cout<<"Wydarzenia :\n";

    int j(0);
    for ( vector<Event *>::iterator itr = eventsVector.begin(), end = eventsVector.end() ; itr != end; ++itr ) {
            cout<<++j<<". "
                <<whatTypeEventIs(*itr);
            (*itr)->printEventInfo();
            cout<<endl;
        }
}

void User::saveUserData()
{

}

