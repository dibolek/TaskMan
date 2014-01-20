#include "allusers.h"
#include "meeting.h"
#include "todolist.h"
#include "note.h"
#include <QtCore/qdatetime.h>
//#include <QtCore/QDate>

#include "date.h"
//#include "datastorage.h"

//#include <qstring>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>


using namespace std;

int main()
{
    srand(time(0));

    AllUsers Users;
    User currentUser;

    Users.addUser(currentUser,"Mama Terenia");
    Users.addUser(currentUser,"Johnny Deep");
    Users.addUser(currentUser,"Huio Iglesias");
    Users.addUser(currentUser,"Tereska I Deska");
    Users.addUser(currentUser,"Ktos Tam");

    vector<UsersListStruct> mainVector = Users.getUsersVector();

    Users.displayUsersInfo();

//-------------generator eventow-------------------------------------------
    cout<<"Jestes zalogowany jako : "<<currentUser.getUserName()
          <<"\n\nTwoje ";
    for (int i = 0; i < 5; ++i) {
            currentUser.addEvent(createRandomValue(3,1),createRandomValue(999,100),createRandomValue(365,1),createRandomValue(24,1),"tresc wiadomosci","miasto",createRandomValue(6,1));
        }
//--------endof

    currentUser.displayEvents();

    DataStorage Storage;
    Storage.allUsersVectorExport( mainVector, "users2.txt");

    Storage.allUsersVectorImport( mainVector, "users3.txt");
    Users.setUsersVector(mainVector);

    Users.displayUsersInfo();



    cin.get();
    return EXIT_SUCCESS;
}

