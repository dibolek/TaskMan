#include "functions.h"


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

int convertStringToInt(string _str)
{
    stringstream ss(_str);
    int x;
    ss >> x;
    return x;
}

//menu przy pierwszym uruchomieniu programu ( dla niezalogowanego usera )
int mainMenu()
{
    system("cls");

    int choice;

    cout << "Aplikacja Kalendarz" << endl << endl;
    cout << "Menu" << endl;
    cout << "1. Zaloguj sie" << endl;
    cout << "2. Zaloz konto" << endl;
    cout << "3. Wyjdz" << endl << endl;
    cout << "$: ";

    cin >> choice;
    return choice;

}

void loggedAs()
{
    cout << "Aplikacja Kalendarz" << endl << endl;
    cout << "Jestes zalogowany jako: ";
}

int menuLogged()
{
    int choice;



    cout << "Menu" << endl;
    cout << "1. Wyswietl kalendarz" << endl;
    cout << "2. Wyswietl zdarzenia" << endl;
    cout << "3. Dodaj zdarzenie" << endl;
    cout << "4. wyloguj sie" << endl << endl;
    cout << "$: ";

    cin >> choice;

    return choice;

}

int menuShowCalendar()
{
    int choice;


    cout << "Menu - wyswietl kalendarz" << endl;
    cout << "1. Wyswietl aktualny miesiac" << endl;
    cout << "2. Wyswietl konkretny meisiac" << endl;
    cout << "3. cofnij" << endl << endl;
    cout << "$: ";

    cin >> choice;

    return choice;
}

int menuShowEvents()
{
    int choice;

    cout << "Menu - wyswietl zdarzenia" << endl;
    cout << "1. Wyswietl najblizsze" << endl;
    cout << "2. Wyswietl z danego miesiac" << endl;
    cout << "3. cofnij" << endl << endl;
    cout << "$: ";

    cin >> choice;

    return choice;
}

int menuAddEvent()
{
    int choice;

    cout << "Menu - dodaj zdarzenie" << endl;
    cout << "1. Notatka" << endl;
    cout << "2. Spotkanie" << endl;
    cout << "3. ToDo List" << endl;
    cout << "3. cofnij" << endl << endl;
    cout << "$: ";

    cin >> choice;

    return choice;
}
