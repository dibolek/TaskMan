#ifndef ALLUSERS_H
#define ALLUSERS_H
#include "user.h"
#include "functions.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct UsersListStruct {
        int userID;
        string userName;
        string fileName;
};

class AllUsers
{
    private:
        vector<UsersListStruct> usersVector;

    public:
//--------------constructors and destructor section ----------------------------
        AllUsers();
        ~AllUsers();

//--------------------- get and set section ------------------------------------
        vector<UsersListStruct> getUsersVector() const;
        void setUsersVector(const vector<UsersListStruct> &value);

//---------------------- other methods -----------------------------------------
        User addUser(string uName);
        void removeUser(int id);
        int getUserCount();

        void displayUsersInfo();
};

#endif // ALLUSERS_H
