#ifndef USER_H
#define USER_H
#include "functions.h"
#include "event.h"
#include "meeting.h"
#include "todolist.h"
#include "note.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <QDateTime>

using namespace std;

class User
{
    private:
        int userID;
        string userName;
        string fileName;
        vector<Event *> eventsVector;
//        struct PointerCompare{
//                bool operator()(const Event* ls, const Event* rs){
//                    return (*ls).getDataIczas() < (*rs).getDataIczas();
//                };
//        };

    public:
//--------------constructors and destructor section ----------------------------
        User(string name, int id, string fname);
        User();
        ~User();

//--------------------- get and set section ------------------------------------
        vector<Event *> getEventsVector() const;
        void setEventsVector(const vector<Event *> &value);
        int getUserID() const;
        void setUserID(int value);
        string getUserName() const;
        void setUserName(const string &value);
        string getFileName() const;
        void setFileName(const string &value);

//---------------------- other methods -----------------------------------------
        void addEvent(int typeOfEvent, QDateTime _dataIczas, string message, string place, int duration);
        void removeEvent(int id);
        int getEventsCount();
        int whatTypeEventIs(Event * p_Event);
        void sortEventsByDate();
        void displayEvents();
        void saveUserData();

};

#endif // USER_H
