#include "functions.h"
#include <allusers.h>

int createRandomValue(int range, int startingPoint)
{
    return ( rand()% range + startingPoint );
}

int getIntegerFromConsole()
{
    int x;
    cin>>x;
    return x;
}

string getStringFromConsole()
{
    string tmp;
    getline(cin,tmp);
    return tmp;
}


//menu przy pierwszym uruchomieniu programu ( dla niezalogowanego usera )
void firstMenu()
{
    char choice;

    cout << "Aplikacja Kalendarz" << endl << endl;
    cout << "Menu" << endl;
    cout << "1. Zaloguj sie" << endl;
    cout << "2. Zaloz konto" << endl;
    cout << "Q. Wyjdz" << endl << endl;
    cout << "$: ";

    cin >> choice;

    while ( putchar(tolower(choice)) != 'q' )
    {
        switch (choice)
        {
            case '1':
                logowanie();
                break;
            case '2':
                rejestracja();
                break;

            default:
                cout << "Nie ma takiej opcji" << endl;
                cout << "Nacisnij dowolny przycisk..." << endl;
                getch();
                break;
        }

        cout << "Aplikacja Kalendarz" << endl << endl;
        cout << "Menu" << endl;
        cout << "1. Zaloguj sie" << endl;
        cout << "2. Zaloz konto" << endl;
        cout << "Q. Wyjdz" << endl << endl;
        cout << "$: ";

        cin >> choice;

    }
}

void logowanie( vector<UsersListStruct> _users )
{
    system("cls");

    string login;

    cout << "Podaj swoj login: ";
    cin login;

    for ( _users::iterator itr = _users.begin(), end = _users.end(); itr != end; i++ )
    {

    }

}


void menuLogged()
{
    char choice;

    cout << "Aplikacja Kalendarz" << endl << endl;
    cout << "Jestes zalogowany jako: " <<
    cout << "Menu" << endl;
    cout << "1. Zaloguj sie" << endl;
    cout << "2. Zaloz konto" << endl;
    cout << "Q. Wyjdz" << endl << endl;
    cout << "$: ";

    cin >> choice;

    while ( putchar(tolower(choice)) != 'q' )
    {
        switch (choice)
        {
            case '1':
                logowanie();
                break;
            case '2':
                rejestracja();
                break;

            default:
                cout << "Nie ma takiej opcji" << endl;
                cout << "Nacisnij dowolny przycisk..." << endl;
                getch();
                break;
        }

        cout << "Aplikacja Kalendarz" << endl << endl;
        cout << "Menu" << endl;
        cout << "1. Zaloguj sie" << endl;
        cout << "2. Zaloz konto" << endl;
        cout << "Q. Wyjdz" << endl << endl;
        cout << "$: ";

        cin >> choice;

    }
}
