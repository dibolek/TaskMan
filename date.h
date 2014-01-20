#ifndef DATE_H
#define DATE_H

#include <QtCore/qdatetime.h>
#include <iostream>

using namespace std;

class Date
{
    public:
        Date();

        QDateTime getDateTimeObject();
        QDateTime getCurrentDateAndTime();
        QDate getDateFromString(string date);
};

#endif // DATE_H
