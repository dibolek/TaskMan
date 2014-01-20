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

    char monthArray[6][7];

    for ( int m=1 ; m<=days ; )
    {
        for ( int i=0 ; i<6 ; i++ )
        {
            for ( int z=0 ; z<weekDay-1 ; z++ )
            {
                monthArray[i][z] = 0;
            }


            for ( int j=(weekDay-1) ; j<7 ; j++)
            {
                monthArray[i][j] = m;
                m++;
            }
        }

        for ( int i=1 ; i<6 ; i++ )
        {
            for ( int j=1 ; j<7 ; j++ )
            {
                monthArray[i][j] = m;
                m++;
            }
        }
    }

    for ( int i=0 ; i<6 ; i++ )
    {
        for ( int j=0 ; j<7 ; j++ )
        {
            cout << setw(3) << monthArray[i][j];
        }
        cout << endl;
    }

}
