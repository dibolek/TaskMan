#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include "allusers.h"

#include <vector>
#include <fstream>

using namespace std;

class DataStorage
{
    public:
        DataStorage();

        void userDataExport(User & usr);
        void userDataImport(User & usr, string _nazwaPliku);

        void allUsersVectorExport(vector<UsersListStruct> &vec, string nazwapliku);
        vector<UsersListStruct> allUsersVectorImport(string nazwapliku);
//        void allUsersVectorImport(vector<UsersListStruct> &vec, string nazwapliku);

};

#endif // DATASTORAGE_H
