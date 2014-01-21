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

    int monthArray[6][7];

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
