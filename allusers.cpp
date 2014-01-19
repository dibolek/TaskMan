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

}

void DataStorage::userDataImport(User &usr)
{

}

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
    x = atoi( y.c_str() );

    vector<UsersListStruct> temporary(x);

    for (vector<UsersListStruct>::iterator itr = temporary.begin(), end = temporary.end(); itr != end; ++itr) {

            getline(plik, y);
            (*itr).userID = atoi(y.c_str());

            getline(plik, y);
            (*itr).userName = y;

            getline(plik, y);
            (*itr).fileName = y;
    }

    plik.close();

    vec = temporary;
}


