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
//        User currentUser;

    public:
//--------------constructors and destructor section ----------------------------
        AllUsers();
        ~AllUsers();

//--------------------- get and set section ------------------------------------
        vector<UsersListStruct> getUsersVector() const;
        void setUsersVector(const vector<UsersListStruct> &value);

//        User getCurrentUser() const;
        //        void setCurrentUser(const User &value);

//---------------------- other methods -----------------------------------------
        void addUser(User &user,string uName);
        void removeUser(int id);
        int getUserCount();

        void displayOptions();
        void displayUsersInfo();

};

class DataStorage
{
    public:
        DataStorage();

        void userDataExport(User & usr);
        void userDataImport(User & usr);

        void allUsersVectorExport(vector<UsersListStruct> &vec, string nazwapliku);
        void allUsersVectorImport(vector<UsersListStruct> &vec, string nazwapliku);

};

#endif // ALLUSERS_H
