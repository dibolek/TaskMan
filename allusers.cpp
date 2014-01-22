#include "allusers.h"


//--------------constructors and destructor section ----------------------------

AllUsers::AllUsers()
{

}

AllUsers::~AllUsers()
{
    usersVector.clear();

}


//--------------------- get and set section ------------------------------------

vector<UsersListStruct> AllUsers::getUsersVector() const
{
    return usersVector;
}

void AllUsers::setUsersVector(const vector<UsersListStruct> &value)
{
    usersVector = value;
}

//User AllUsers::getCurrentUser() const
//{
//    return currentUser;
//}

//void AllUsers::setCurrentUser(const User &value)
//{
//    currentUser = value;
//}

//---------------------- other methods -----------------------------------------

void AllUsers::addUser(User &user, string uName)
{
    bool value=1;
    int id;
    while (value) {
            value = 0;
            id = createRandomValue(9000,1000);
            for (vector<UsersListStruct>::iterator itr = usersVector.begin(), end = usersVector.end(); itr != end; ++itr)
            {
                if ( id == (*itr).userID ){
                        value = 1;
                        break;
                }
            }
    }


//    currentUser=userTmp;

    UsersListStruct curUser;
    curUser.userName = uName;
    curUser.userID = id;
    stringstream sout;
    sout << id << ".txt";
    curUser.fileName = sout.str();
    usersVector.push_back(curUser);

    User userTmp(uName,id,curUser.fileName);
    user=userTmp;
//    return (&user);
//    usersVector.push_back(userTmp);
}

void AllUsers::removeUser(int id)
{

}

int AllUsers::getUserCount()
{
    return static_cast<int>( usersVector.size() );
}

void AllUsers::displayOptions()
{

}

void AllUsers::displayUsersInfo()
{
    cout<<"Dostepni uzytkownicy:\n";
    int j(0);
    for ( vector<UsersListStruct>::iterator itr = usersVector.begin(), end = usersVector.end() ; itr != end; ++itr ) {
            cout<<++j<<". "<<(*itr).userName<<" ( id - "
               <<(*itr).userID<<" ), filename : "<<(*itr).fileName<<"."<<endl;
    }
    cout<<endl<<endl;
}






//---------------------------- DataStorage Class definitions ------------------

DataStorage::DataStorage()
{
}

void DataStorage::userDataExport(User &usr)
{
    vector<Event *> tmp = usr.getEventsVector();
    Date datetime;

    ofstream plik( usr.getFileName().c_str() );
    plik << tmp.size() << endl
         << usr.getUserID() << endl
         << usr.getUserName() << endl
         << usr.getFileName() << endl;

    for (vector<Event *>::iterator itr = tmp.begin(), end = tmp.end() ; itr != end ; ++itr) {
           datetime.setDateAndTimeObject( (*itr)->getDataIczas() );
           Event * p_Event = *itr;
           Meeting *p_Meeting = 0;
           ToDoList *p_ToDoList = 0;
           Note *p_Note = 0;
           // type : 1 - meeting, 2 - todolist, 3 -note
           if( (p_Meeting = dynamic_cast<Meeting*>(p_Event)) ){
                plik << 1 << endl
                     << p_Meeting->getPlaceOfMeeting() << endl
                     << p_Meeting->getDurationOfMeeting() << endl;

           }else if ( (p_ToDoList = dynamic_cast<ToDoList*>(p_Event)) ) {
                       plik << 2 << endl
                            << "nothing" << endl
                            << 0 << endl;

                 }else if ( (p_Note = dynamic_cast<Note*>(p_Event)) ) {
                            plik << 3 << endl
                                 << "nothing" << endl
                                 << 0 << endl;
                       }
           plik << p_Event->getEventID() << endl
                << p_Event->getMessage() << endl
                << datetime.ExportDateAndTimeToString() << endl;
    }//for

    plik.flush();
    plik.close();

}//userDataExport

void DataStorage::userDataImport(User &usr, string _nazwaPliku)
{
    ifstream plik(_nazwaPliku.c_str());

    Date datetime;
    int x;
    string y;

    getline(plik, y);
    int eventsCount = convertStringToInt( y );
    vector<Event *> tmp;

    getline(plik, y);
    usr.setUserID( convertStringToInt( y ) );
    getline(plik, y);
    usr.setUserName( y );
    getline(plik, y);
    usr.setFileName( y );

    Event * p_Event = 0;
    Meeting *p_Meeting = 0;
    
    for (int i = 0; i < eventsCount; ++i) {
            getline(plik, y);
            x = convertStringToInt( y );

            if ( x == 1 ) {
                 p_Meeting = new Meeting();
                 getline(plik, y);
                 p_Meeting->setPlaceOfMeeting( y );
                 getline(plik, y);
                 p_Meeting->setDurationOfMeeting( convertStringToInt( y ) );
                 p_Event = dynamic_cast<Event*>(p_Meeting);
                }else if ( x == 2 ) {
                    p_Event = new ToDoList();
                    getline(plik, y);
                    getline(plik, y);
                }else if ( x == 3 ) {
                    p_Event = new Note();
                    getline(plik, y);
                    getline(plik, y);
                }
            getline(plik, y);
            p_Event->setEventID( convertStringToInt( y ) );
            getline(plik, y);
            p_Event->setMessage( y );

            getline(plik, y);
            datetime.ImportDateAndTimeFromString(y);
            p_Event->setDataIczas( datetime.getDateAndTimeObject() );
            tmp.push_back(p_Event);
    }//for
    usr.setEventsVector(tmp);
    plik.close();
}//dataStorage

void DataStorage::allUsersVectorExport(vector<UsersListStruct> &vec, string nazwapliku)
{
    ofstream plik(nazwapliku.c_str());
//    vector<UsersListStruct> mainVector = Users.getUsersVector();
    plik << vec.size() << endl;
    for (vector<UsersListStruct>::iterator itr = vec.begin(), end = vec.end(); itr != end; ++itr) {
            plik << (*itr).userID   << endl
                 << (*itr).userName << endl
                 << (*itr).fileName << endl;
        }
    plik.flush();
    plik.close();

}

void DataStorage::allUsersVectorImport(vector<UsersListStruct> &vec, string nazwapliku)
{
    ifstream plik(nazwapliku.c_str());
    int x;
    string y;
    getline(plik, y);
    x = convertStringToInt(y);

    vector<UsersListStruct> temporary(x);

    for (vector<UsersListStruct>::iterator itr = temporary.begin(), end = temporary.end(); itr != end; ++itr) {

            getline(plik, y);
            (*itr).userID = convertStringToInt(y);

            getline(plik, y);
            (*itr).userName = y;

            getline(plik, y);
            (*itr).fileName = y;
    }

    plik.close();

    vec = temporary;
}


