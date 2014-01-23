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

//---------------------- other methods -----------------------------------------

User AllUsers::addUser(string uName)
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


    UsersListStruct curUser;
    curUser.userName = uName;
    curUser.userID = id;
    stringstream sout;
    sout << id << ".txt";
    curUser.fileName = sout.str();
    usersVector.push_back(curUser);
    User usrTmp(uName,id,curUser.fileName);

    return usrTmp;

}

void AllUsers::removeUser(int id)
{
    usersVector.erase(usersVector.begin() + (id -1));
    string tmpStr = usersVector[id-1].fileName;
    char* fName = new char[tmpStr.size()+1];
    copy(tmpStr.begin(),tmpStr.end(),fName);
    fName[tmpStr.size()]='\0';
    remove(fName);
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
//    cout<<"Dostepni uzytkownicy:\n";
    int j(0);
    for ( vector<UsersListStruct>::iterator itr = usersVector.begin(), end = usersVector.end() ; itr != end; ++itr ) {
            cout<<++j<<". "<<(*itr).userName<<" ( UserID - "
               <<(*itr).userID<<" )."<<endl;
    }
}


