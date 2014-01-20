#include "calendar.h"

Calendar::Calendar()
{
}

void Calendar::displayCalendar(int month, int year)
{
    QDate data = QDate(year, month, 01);
    int days = data.daysInMonth();
    int weekDay = data.dayOfWeek();

    int monthArray[6][7];

    for ( int i=0 ; i<6 ; i++ )
    {
        for ( int j=0 ; j<7 ; j++)
        {

        }

    }
}
