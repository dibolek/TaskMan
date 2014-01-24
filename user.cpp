#include "user.h"

//--------------constructors and destructor section ----------------------------
User::User(string name, int id, string fname)
{
    userID = id;
    userName = name;
    fileName = fname;
}

User::User()
{
    userID = 0;
    userName = "Unknown";
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

void User::setEventsVector(const vector<Event *> &value)
{
    eventsVector = value;
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
void User::addEvent(int typeOfEvent, QDateTime _dataIczas, string message, string place, int duration)
{
    Event * eventTMP = 0;
    bool val=1;
    int id;

    while (val) {
            val=0;
            id = createRandomValue(999,100);

            for (vector<Event*>::iterator itr = eventsVector.begin(), end = eventsVector.end(); itr != end; ++itr) {
                    if ( id == (*itr)->getEventID() ) {
                            val = 1;
                            break;
                    }//if
            }//for
    }//while

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

void User::removeEvent(int id)
{
    eventsVector.erase(eventsVector.begin() + (id - 1));
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

void User::sortEventsByDate()
{
    sort(eventsVector.begin(),eventsVector.end(),Event::PointerCompare());
}

void User::displayEvents()
{
    int j(0);
    for ( vector<Event *>::iterator itr = eventsVector.begin(), end = eventsVector.end() ; itr != end; ++itr ) {
            cout<<++j<<". ";
            (*itr)->printEventInfo();
            cout<<endl;
        }
}

void User::saveUserData()
{

}


