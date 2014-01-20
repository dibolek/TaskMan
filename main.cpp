#include "allusers.h"

#include "meeting.h"
#include "todolist.h"
#include "note.h"
//#include "datastorage.h"

//#include <qstring>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>




//serialization libraries
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//namespace boost {
//namespace serialization {
//class access;
//}
//}
//end of serialization

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





/*   zapis wydarzen z sortowaniem --------------------------------

    Meeting *wskMeeting;
    ToDoList *wskToDO;
    Note *wskNote;
    Event *wskEvent;

    if ( wskMeeting = dynamic_cast<Meeting*>(wskEvent) ) {
            zapis meeting
        } else {
        } if ( wskToDO = dynamic_cast<ToDoList*>(wskEvent) ){
            zapis todolist
        } else ( wskNote = dynamic_cast<Note*>(wskEvent) ) {
            zapis note
        }
-----------------------------------------------------------------*/


//-------------------serialization code----------------------------------------
//    {
//    ofstream plikser( "usrs_ser.txt" );
//    boost::archive::text_oarchive ar(plikser);
//    ar & Users;
//    }
//-------------------endof-----------------------------------------------------



    cin.get();
    return EXIT_SUCCESS;
}

