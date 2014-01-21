#include "calendar.h"
#include <iomanip>

using namespace std;

Calendar::Calendar()
{
}

void Calendar::displayCalendar( Date &data )
{
    //data.setDate(01,month,year);
    int days = data.getMainDate().date().daysInMonth();
    int weekDay = data.getMainDate().date().dayOfWeek();

    char weekDays[7] = {'P','W','S','C','P','S','N'};
    const char *Months[] = {"Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik","Listopad","Grudzien"};

    int licznik = 1;
    int tablica[6][7];

    // wypelnianie tablicy
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            tablica [i][j] = 0;
        }
    }

    for (int i = 0; i < 6; ++i)
    {
        if ( i != 0)
        {
            for (int j = 0 ; j < 7; ++j, ++licznik, --days)
            {
                if (days > 0)
                    {
                        tablica[i][j] = licznik;
                    }
            }
        }
        else
        {
            for (int j = weekDay ; j <= 7; ++j, ++licznik, --days)
            {
                tablica[0][j-1] = licznik;
            }
        }

    }

    //wyswietlenie miesiaca
    cout << Months[data.getMainDate().date().month()-1] << " " << data.getMainDate().date().year();
    cout << endl << endl;

    //wyswietlenie dni tygodnia
    for ( int i=0 ; i<7 ; i++ )
    {
        cout << setw(3) << weekDays[i];
    }

    cout << endl;

    //wyswietlenie calego miesiaca
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if ( tablica [i][j] == 0)
            cout << setw(3) << " ";
            else
            cout << setw(3) << tablica [i][j];
        }
        cout << endl;
    }

    cout << "Dzisiaj mamy: " << data.getStringFromDate(data.getMainDate().date().currentDate()) << endl << endl;

}
