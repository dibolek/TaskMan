#include "functions.h"


int createRandomValue(int range, int startingPoint)
{
    return ( rand()% range + startingPoint );
}

bool integerCin(int &integer){
    cin.clear();
    cin.sync();
    cin >> integer;
    return cin.good();
}

int getIntegerFromConsole()
{
    int x;
    bool state;
    do{
            state = integerCin(x);
            if(!state) cout << "Musisz wprowadzic liczbe, sprobuj ponownie : ";
        }while(!state);
    return x;
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
    clearScreen();


    cout << "Aplikacja Kalendarz" << endl << endl;
    cout << "Menu" << endl;
    cout << "1. Zaloguj sie" << endl;
    cout << "2. Zaloz konto" << endl;
    cout << "3. Usun uzytkownika" << endl;
    cout << "4. Wyjdz" << endl << endl;
    cout << "$: ";

    int choice = getIntegerFromConsole();
    return choice;

}

void loggedAs()
{
    cout << "Aplikacja Kalendarz" << endl << endl;
    cout << "Jestes zalogowany jako: ";
}

int menuLogged()
{
    cout << "Menu" << endl;
    cout << "1. Wyswietl kalendarz" << endl;
    cout << "2. Wyswietl zdarzenia" << endl;
    cout << "3. Dodaj zdarzenie" << endl;
    cout << "4. wyloguj sie" << endl << endl;
    cout << "$: ";

    int choice = getIntegerFromConsole();
    return choice;

}

int menuShowCalendar()
{
    cout << "Menu - wyswietl kalendarz" << endl;
    cout << "1. Wyswietl aktualny miesiac" << endl;
    cout << "2. Wyswietl konkretny meisiac" << endl;
    cout << "3. cofnij" << endl << endl;
    cout << "$: ";

    int choice = getIntegerFromConsole();
    return choice;
}

int menuShowEvents()
{
    cout << "Menu - wyswietl zdarzenia" << endl;
    cout << "1. Wyswietl najblizsze" << endl;
    cout << "2. Wyswietl z danego miesiac" << endl;
    cout << "3. Wyswietl z danego miesiac" << endl;
    cout << "4. cofnij" << endl << endl;
    cout << "$: ";

    int choice = getIntegerFromConsole();
    return choice;
}

int menuAddEvent()
{
    cout << "Menu - dodaj zdarzenie" << endl<< endl;
    cout << "1. Spotkanie" << endl;
    cout << "2. Zadanie" << endl;
    cout << "3. Notatka" << endl;
    cout << "4. cofnij" << endl << endl;
    cout << "$: ";

    int choice = getIntegerFromConsole();
    return choice;
}

void pause()
{
    system("pause");
}


void clearScreen()
{
    system("cls");
}
