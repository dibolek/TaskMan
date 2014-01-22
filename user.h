#ifndef USER_H
#define USER_H
#include "functions.h"
#include "meeting.h"
#include "todolist.h"
#include "note.h"

#include <vector>
#include <iostream>

using namespace std;

class User
{
    private:
        int userID;
        string userName;
        string fileName;
        vector<Event *> eventsVector;

    public:
//--------------constructors and destructor section ----------------------------
        User(string name, int id, string fname);
        User();
        ~User();

//--------------------- get and set section ------------------------------------
        vector<Event *> getEventsVector() const;
        int getUserID() const;
        void setUserID(int value);
        string getUserName() const;
        void setUserName(const string &value);
        string getFileName() const;
        void setFileName(const string &value);

//---------------------- other methods -----------------------------------------
        void addEvent(int typeOfEvent, int id, QDateTime _dataIczas, string message, string place, int duration);
        void removeEvent();
        int getEventsCount();
        int whatTypeEventIs(Event * p_Event);
        void sortEvents();
        void displayEvents();
        void saveUserData();

};

#endif // USER_H
