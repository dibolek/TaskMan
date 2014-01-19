#ifndef ALLUSERS_H
#define ALLUSERS_H
#include "user.h"
#include "functions.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

//#include <boost/serialization/vector.hpp>

using namespace std;

//namespace boost {
//namespace serialization {
//class access;
//}
//}

struct UsersListStruct {
        int userID;
        string userName;
        string fileName;

//serialization code
//        UsersListStruct() : userID(0), userName("Unknown"), fileName("unknown.txt") {};
//        friend class boost::serialization::access;
//        template<typename Archive>
//        void serialize(Archive& ar, const unsigned version){
//            ar & userID & userName & fileName;
//        }

// end of serialization
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

//serialization code
//    private:
//        friend class boost::serialization::access;
//        template<typename Archive>
//        void serialize(Archive& ar, std::vector<UsersListStruct>& objs, const unsigned version){
//            ar & objs;
//        }

//end of serialization
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
