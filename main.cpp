#include "allusers.h"
#include "meeting.h"
#include "todolist.h"
#include "note.h"
#include <QtCore/qdatetime.h>
#include <calendar.h>
//#include <QtCore/QDate>
#include <date.h>

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
    AllUsers users;
    DataStorage storage;
    User currentUser;
    vector<UsersListStruct> mainVector;
    vector<Event*> eventVectorTmp;
    storage.allUsersVectorImport(mainVector,"users.txt");

    users.setUsersVector(mainVector);

    Date coreDate;
    Calendar kalendarz;

    int choice;

    do
    {

                                                                //wyswitlenie menu glownego
        choice = mainMenu();                                    //1 - zaloguj sie
                                                                //2 - zaloz konto
        switch (choice) {                                       //3 - wyjscie z programu
        case 1: //mainMenu-zaloguj sie
        {
            system("cls");
            cout << "Wybierz uzytkownika:" << endl << endl;

            users.displayUsersInfo();

            int _id;

            cout << endl << endl << "$: ";

            cin >> _id;

            string _file = mainVector[_id-1].fileName;
            storage.userDataImport(currentUser,_file);

            do
            {

            system("cls");
            loggedAs();
            cout << currentUser.getUserName();
            choice = menuLogged();



            switch (choice) {
            case 1: //mainMenu-menuLogged-wyswietl kalendarz
            {
                do
                {
                    system("cls");

                    loggedAs();
                    cout << currentUser.getUserName();
                    choice = menuShowCalendar();

                    switch (choice) {
                    case 1: //mainMenu-menuLogged-wyswietl kalendarz-wyswietl aktualny miesiac
                        system ("cls");
                        loggedAs();
                        cout << currentUser.getUserName() << endl << endl;

                        coreDate.setCurrentDateAndTime();

                        kalendarz.displayCalendar(coreDate);

                        cout << "Nacisnij dowolny klawisz ...";

                        cin.get();
                        cin.get();
                        break;
                    case 2: //mainMenu-menuLogged-wyswietl kalendarz-wyswietl konkretny miesiac
                    {
                        system("cls");
                        string _date;
                        loggedAs();
                        cout << currentUser.getUserName() << endl << endl;

                        cout << "Podaj date ( dd-MM-yyyy ): ";
                        cin >> _date;

                        system("cls");

                        coreDate.setDateFromString(_date);
                        kalendarz.displayCalendar(coreDate);

                        cout << endl << endl << "Nacisnij dowolny klawisz...";
                        cin.get();
                        cin.get();


                        break;
                    }
                    default:
                        cout << "Nie ma takiej opcji!";
                        cin.get();
                        cin.get();
                        break;
                    }
                }
                while(choice != 3);
                break;
            }

            case 2: //mainMenu-menuLogged-wyswietl zdarzenia
            {
                do
                {
                    system("cls");
                    loggedAs();                                 //1 - wyswietl najblizsze
                    cout << currentUser.getUserName();          //2 - wyswietl z danego miesiaca
                    choice = menuShowEvents();                  //3 - cofnij

                    switch (choice) {
                    case 1: //mainMenu-menuLogged-wyswietl zdarzenia-wyswietl najblizsze
                    {
                        system("cls");
                        loggedAs();
                        cout << currentUser.getUserName() << endl << endl;

                        QDateTime tmpDate = QDateTime::currentDateTime();
                        tmpDate = tmpDate.addDays(14);

                        QDateTime tmpDate2 = QDateTime::currentDateTime();
                        eventVectorTmp = currentUser.getEventsVector();
                        Event* p_tmp = 0;
                        for ( vector<Event*>::iterator itr = eventVectorTmp.begin(), end = eventVectorTmp.end(); itr != end; ++itr){
                                p_tmp = (*itr);
                                if ( p_tmp->getDataIczas() > tmpDate2 && p_tmp->getDataIczas() < tmpDate )
                                    {
                                        p_tmp->printEventInfo();
                                    }
                            }
                        cin.get();
                        cin.get();
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        loggedAs();
                        cout << currentUser.getUserName() << endl << endl;

                        //zrobic pobieranie daty i na jej podstawie obliczyc poczatek i koneic miesiaca

                        string data;
                        coreDate.setCurrentDateAndTime();

                        cout << "Podaj date ( dd-MM-yyyy ): ";
                        cin >> data;

                        coreDate.setDateFromString(data);

                        int day = coreDate.getDateAndTimeObject().date().day();
                        cout << "dzien miesiaca: " << day << endl;
                        QDateTime tmpDate = coreDate.getDateAndTimeObject().addDays(-day+1);
                        tmpDate.time().setHMS(23,59,59);    //trzeba ustawic godziny na 00:00 i 23:59
                        cout << tmpDate.toString("hh:mm").toStdString() << endl;
                        cout << tmpDate.toString("dd-MM-yyyy hh:mm").toStdString() << endl;


                        int days = coreDate.getDateAndTimeObject().date().daysInMonth();
                        cout << "ile dni w miesiacu: " << days << endl;
                        QDateTime tmpDate2 = tmpDate.addDays(days-1);
                        tmpDate.fromString("23:59","hh:mm");        //trzeba ustawic godziny na 00:00 i 23:59
                        cout << tmpDate2.toString("dd-MM-yyyy hh:mm").toStdString() << endl;


                        eventVectorTmp = currentUser.getEventsVector();
                        Event* p_tmp = 0;
                        for ( vector<Event*>::iterator itr = eventVectorTmp.begin(), end = eventVectorTmp.end(); itr != end; ++itr){
                                p_tmp = (*itr);
                                if ( p_tmp->getDataIczas() >= tmpDate && p_tmp->getDataIczas() <= tmpDate2 )
                                    {
                                        p_tmp->printEventInfo();
                                    }
                            }
                        cin.get();
                        cin.get();
                        break;
                    }
                    default:
                        break;
                    }
                }
                while(choice!=3);
                break;
            }

            default:
                break;
            }
            }
            while(choice!=4);


            break;
        }
        default:
            break;
        }
    }
    while(choice!=3);






//    QDateTime qdt = QDateTime::currentDateTime();
//    Meeting meet(255,qdt,"wiadomosc testowa","glowno", 2);

//    meet.printEventInfo();

//    Note notka(264,qdt,"tresc naszej otatki jest tutaj");
//    notka.printEventInfo();

//    ToDoList todo(98,qdt,"trzeba obciagnac sloniowi");
//    todo.printEventInfo();



//    srand(time(0));

//    AllUsers Users;
//    User currentUser;


//    /* inicjalizacja daty na ktorej bedziemy operowac podczas pracy
//     * calego programu przy pomocy aktualnej daty systemowej */

//    cout << endl << endl ;

//    Date coreDate;
//    Calendar kalendarz;

//    kalendarz.displayCalendar(coreDate);

//    coreDate.setDate(1,2,2014);
//    kalendarz.displayCalendar(coreDate);

//    coreDate.setDate(1,3,2014);
//    kalendarz.displayCalendar(coreDate);

////    cout << "Dzisiaj mamy: " << coreDate.getStringFromDate(coreDate.getDateAndTimeObject().date()) << endl << endl;




//    Users.addUser(currentUser,"Mama Terenia");
//    Users.addUser(currentUser,"Johnny Deep");
//    Users.addUser(currentUser,"Huio Iglesias");
//    Users.addUser(currentUser,"Tereska I Deska");
//    Users.addUser(currentUser,"Ktos Tam");



//    vector<UsersListStruct> mainVector = Users.getUsersVector();

//    Users.displayUsersInfo();

////-------------generator eventow-------------------------------------------
//    cout<<"Jestes zalogowany jako : "<<currentUser.getUserName()
//          <<"\n\nTwoje ";
//    for (int i = 0; i < 5; ++i, coreDate.setDate( createRandomValue(30,1), createRandomValue(12,1),createRandomValue(5,2014) ) ) {
//            currentUser.addEvent( createRandomValue(3,1) , createRandomValue(999,100) , coreDate.getDateAndTimeObject() ,"tresc wiadomosci","miasto",createRandomValue(6,1));
//        }
////--------endof

//    currentUser.displayEvents();


//    // Test exportu danych uzytkownika -----------------------------------
//    DataStorage Storage;
//    Storage.allUsersVectorExport( mainVector, "users2.txt");
//    Storage.allUsersVectorImport( mainVector, "users3.txt");
//    Users.setUsersVector(mainVector);
//    Users.displayUsersInfo();
//    Storage.userDataExport(currentUser);
//    //--------------------------------------------------------------------

//    //test importu danych uzytkownika ------------------------------------
//    User currentUser2;
//    Storage.userDataImport(currentUser2,currentUser.getFileName());
//    currentUser2.displayEvents();
//    //--------------------------------------------------------------------



    cin.get();
    return EXIT_SUCCESS;
}

