#include "calendar.h"
#include <iomanip>

using namespace std;

Calendar::Calendar()
{
}

void Calendar::displayCalendar(int month, int year)
{
    QDate data = QDate(year, month, 01);
    int days = data.daysInMonth();
    int weekDay = data.dayOfWeek();

    char weekDays[7] = {'P','W','S','C','P','S','N'};
    const char *Months[] = {"Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik","Listopad","Grudzien"};

    int licznik = 1;
    int tablica[6][7];


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
    cout << Months[data.month()-1];
    cout << endl;

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
        cout<<endl;
    }



}
