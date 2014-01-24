#include "allusers.h"
#include "meeting.h"
#include "todolist.h"
#include "note.h"
#include "functions.h"
#include <QtCore/qdatetime.h>
#include <calendar.h>
//#include <QtCore/QDate>
#include <date.h>

#include "date.h"
#include "datastorage.h"

//#include <qstring>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>

#define MIN_YEAR_ACCEPTED 1900
#define MAX_YEAR_ACCEPTED 2100


using namespace std;

int main()
{
    AllUsers users;
    DataStorage storage;
    User currentUser;

    ifstream plik("users.txt");
    if(!plik.is_open())
    {
        ofstream plik("users.txt");
        plik << 0;
    }
    plik.close();

    vector<Event*> eventVectorTmp;
    users.setUsersVector( storage.allUsersVectorImport("users.txt") );

    Date coreDate;
    Calendar kalendarz;

    int choice;

    do
    {

        choice = mainMenu();                                    //1 - zaloguj sie
                                                                //2 - zaloz konto
        switch (choice) {                                       //3 - wyjscie z programu
        case 1: //mainMenu-zaloguj sie
        {
            int _id;
            int usersCount = users.getUserCount();
            if ( users.getUsersVector().empty() )
            {
                clearScreen();
                cout << "Brak uzytkownikow. Zaloz konto." << endl;
                pause();
            }
            else
            {
                do{
                clearScreen();
                cout << "Wybierz uzytkownika:" << endl << endl;
                users.displayUsersInfo();
                cout << endl;
                cout << usersCount + 1 << ". Powrot do menu glownego.";
                cout << endl << endl << "$: ";
                _id = getIntegerFromConsole();
                }while( !(_id > 0 && _id <= (usersCount + 1) ) );

                if( _id == (usersCount+1) ) break;
                string _file = users.getUsersVector()[_id-1].fileName;
    //            string _file = mainVector[_id-1].fileName;
                storage.userDataImport(currentUser,_file);

                int choice;
                do
                {
                clearScreen();
                loggedAs();
                cout << currentUser.getUserName() << endl << endl;
                choice = menuLogged();

                switch (choice) {
                case 1: //mainMenu-menuLogged-wyswietl kalendarz
                {
                            int choice;
                    do
                    {
                        clearScreen();

                        loggedAs();
                        cout << currentUser.getUserName() << endl << endl;
                        choice = menuShowCalendar();

                        switch (choice) {
                        case 1: //mainMenu-menuLogged-wyswietl kalendarz-wyswietl aktualny miesiac
                            system ("cls");
                            loggedAs();
                            cout << currentUser.getUserName() << endl << endl;

                            coreDate.setCurrentDateAndTime();

                            kalendarz.displayCalendar(coreDate);

                           pause();
                            break;
                        case 2: //mainMenu-menuLogged-wyswietl kalendarz-wyswietl konkretny miesiac
                        {
                            clearScreen();
                            string _date;
                            loggedAs();
                            cout << currentUser.getUserName() << endl << endl;

                            cout << "Podaj date ( dd-MM-yyyy ): ";
                            cin >> _date;

                            clearScreen();

                            loggedAs();
                            cout << currentUser.getUserName() << endl << endl;

                            coreDate.setDateFromString(_date);
                            kalendarz.displayCalendar(coreDate);

                            cout << endl << endl;
                            pause();


                            break;
                        }
                        default:
                            cout << "Nie ma takiej opcji!";
                            pause();
                            break;
                        }
                    }
                    while(choice != 3);
                    break;
                }

                case 2: //mainMenu-menuLogged-wyswietl zdarzenia
                {
                            if(currentUser.getEventsCount()==0) {
                                    clearScreen();
                                    cout << "Nie masz zadnych zdarzen. Utworz nowe zdarzenia."<<endl;
                                    pause();
                                    break;
                                }

                                int choice;

                    do
                    {
                        clearScreen();
                        loggedAs();                                 //1 - wyswietl najblizsze
                        cout << currentUser.getUserName() << endl << endl;          //2 - wyswietl z danego miesiaca
                        choice = menuShowEvents();                  //3 - cofnij

                        switch (choice) {
                        case 1: //mainMenu-menuLogged-wyswietl zdarzenia-wyswietl najblizsze
                        {
                            clearScreen();
                            loggedAs();
                            cout << currentUser.getUserName() << endl << endl;

                            QDateTime tmpDate = QDateTime::currentDateTime();
                            tmpDate = tmpDate.addDays(14);

                            QDateTime tmpDate2 = QDateTime::currentDateTime();
                            tmpDate2 = tmpDate2.addSecs(-3600);
                            eventVectorTmp = currentUser.getEventsVector();
                            Event* p_tmp = 0;
                            int licznik = 0;
                            bool niemazdarzen = 1;
                            for ( vector<Event*>::iterator itr = eventVectorTmp.begin(), end = eventVectorTmp.end(); itr != end; ++itr){
                                    p_tmp = (*itr);
                                    if ( p_tmp->getDataIczas() > tmpDate2 && p_tmp->getDataIczas() < tmpDate )
                                        {
                                            niemazdarzen = 0;                                            cout << ++licznik << ". ";
                                            p_tmp->printEventInfo();
                                        }
                                }
                            if (niemazdarzen){
                                    clearScreen();
                                    cout << "Nie masz zadnych zdarzen w ciagu najblizszych 14 dni." << endl;
                                };


                            pause();
                            break;
                        }
                        case 2: //mainMenu-menuLogged-wyswietl zdarzenia-wyswietl z danego msc
                        {
                            clearScreen();
                            loggedAs();
                            cout << currentUser.getUserName() << endl << endl;

                            int year, month;
                            do{
                            cout<< "Podaj rok : ";
                            year = getIntegerFromConsole();
                            }while( !(year != 0 && year > MIN_YEAR_ACCEPTED && year < MAX_YEAR_ACCEPTED)  );
                            do{
                                  cout << "Podaj miesiac : ";
                                  month = getIntegerFromConsole();
                            }while(!(month > 0 && month < 13));

                            coreDate.setDate(1,month,year);
                            coreDate.setTime(0,0,0);

                            int daysinmonth = coreDate.getDaysInMonth();

                            QDateTime enddate = coreDate.addDays(daysinmonth);
                            cout << "\nDays in month int :" << daysinmonth;

                            //-------------- wyswietlenie zakresu i zdarzen --------------------

                            system("cls");
                            loggedAs();
                            cout << currentUser.getUserName() << endl << endl;
                            cout << "Wybrany zakres: ";
//                            cout << tmpDate.toString("dd-MM-yyyy hh:mm:ss").toStdString();
                            cout << coreDate.getDateAndTimeObject().toString("dd-MM-yyyy hh:mm:ss").toStdString();
                            cout << " - ";
//                            cout << tmpDate2.toString("dd-MM-yyyy hh:mm:ss").toStdString() << endl << endl;
                            cout << enddate.addSecs(-1).toString("dd-MM-yyyy hh:mm:ss").toStdString() << endl << endl;


                            eventVectorTmp = currentUser.getEventsVector();
                            Event* p_tmp = 0;
                            for ( vector<Event*>::iterator itr = eventVectorTmp.begin(), end = eventVectorTmp.end(); itr != end; ++itr){
                                    p_tmp = (*itr);
                                    if ( (p_tmp->getDataIczas() >= coreDate.getDateAndTimeObject()) && (p_tmp->getDataIczas() <= enddate) )
                                        {
                                            p_tmp->printEventInfo();
                                        }
                                }
                            pause();
                            break;
                        }
                        case 3:

                                clearScreen();
                                loggedAs();
                                cout << currentUser.getUserName() << endl << endl;

                                currentUser.displayEvents();
                                pause();

                                break;
                        default:
                            break;
                        }
                    }
                    while(choice!=4);
                    break;
                }

                case 3: //mainMenu-menuLogged-dodaj zdarzenia
                        {

                            int choice;
                            do{
                              clearScreen();
                              choice = menuAddEvent();
                              clearScreen();
                              int year, month, day, hour, min, duration, daysInMonth;
                              string place, message;

                              if(choice==4) break;

                              if(choice == 1) cout << "Dodajesz spotkanie" << endl << endl;
                              else if(choice == 2) cout << "Dodajesz zadanie" << endl << endl;
                              else if(choice == 3) cout << "Dodajesz notatke" << endl << endl;

            //                  if ( (choice != 3) && (choice != 4) ) {
                                      if ( choice != 3 ) {
                                      cout << "Wczytywanie daty i czasu ";

                                      if (choice == 1) {
                                              cout << "rozpoczecia spotkania.";
                                          }else
                                          cout << "wykonania zadania.";
                                      do{
                                      cout<< "\nPodaj rok : ";
                                      year = getIntegerFromConsole();
                                      }while( !(year != 0 && year > MIN_YEAR_ACCEPTED && year < MAX_YEAR_ACCEPTED)  );
                                      do{
                                            cout << "Podaj miesiac : ";
                                            month = getIntegerFromConsole();
                                      }while(!(month > 0 && month < 13));

                                      coreDate.setDate(1,month,year);
                                      daysInMonth = coreDate.getDaysInMonth();

                                      do{
                                            cout << "Podaj dzien : ";
                                            day = getIntegerFromConsole();
                                      }while(!(day > 0 && day <= daysInMonth));

                                      do{
                                            cout << "Podaj godzine : ";
                                            hour = getIntegerFromConsole();
                                      }while(!(hour >= 0 && hour < 24) );

                                      do{
                                              cout << "Podaj minuty : ";
                                              min = getIntegerFromConsole();
                                      }while(!(min >= 0 && min < 60) );

                                      coreDate.setDate(day,month,year);
                                      coreDate.setTime(hour,min,0);

                              }else coreDate.setCurrentDateAndTime();
            //                    }else if ( choice !=4 ) coreDate.setCurrentDateAndTime();


                              if (choice == 1) {
                                      cout << "Podaj miejsce spotkania : ";
                                      cin.get();
                                      getline(cin,place);
                                      do{
                                      cout << "Podaj czas trwania spotkania (w godz) : ";
                                      duration = getIntegerFromConsole();
                                      }while(!(duration >=0 && duration <=24));
                              }

                              if(choice == 1) cout << "Podaj dodatkowe informacje : " ;
                              else if(choice == 3) cout << "Wpisz tresc notatki :" ;
                              else if(choice == 2) cout << "Wpisz co masz do zrobienia :" ;

                              cin.get();
                              getline(cin,message);
                              currentUser.addEvent(choice,coreDate.getDateAndTimeObject(),message,place,duration);
                              currentUser.sortEventsByDate();
                              currentUser.displayEvents();
                              storage.userDataExport(currentUser);

                              }while(true);
                        }

                default:
                    break;
                }
                }
                while(choice!=4);

            }
            break;
        }


        case 2:  //mainMenu-zaloz konto
        {
            clearScreen();

            string name;

            cout << "Podaj nazwe uzytkownika: ";
            cin.get();
            getline(cin,name);

            User usrTmp = users.addUser(name);
            storage.userDataExport(usrTmp);
            vector<UsersListStruct> uVecTmp;
            uVecTmp = users.getUsersVector();
            storage.allUsersVectorExport(uVecTmp,"users.txt");
        }
            break;

        case 3:     //mainMenu-usun konto
        {
            clearScreen();

            int _id;

            if ( users.getUsersVector().empty() )
            {
                cout << "Brak uzytkownikow." << endl;
                pause();
            }
            else
            {
                int usersCount = users.getUserCount();
                do{
                cout << "Wybierz uzytkownika do usuniecia:" << endl << endl;
                users.displayUsersInfo();
                cout << endl;
                cout << usersCount + 1 << ". Powrot do menu glownego.";
                cout << endl << endl << "$: ";
                _id = getIntegerFromConsole();

                }while( !(_id > 0 && _id <= (usersCount + 1) ) );

                if( _id == (usersCount+1) ) break;

                users.removeUser(_id);
                vector<UsersListStruct> uVecTmp = users.getUsersVector();
                storage.allUsersVectorExport(uVecTmp,"users.txt");

            }
        }
            break;

        default:
            break;
        }
    }
    while(choice!=4);






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

