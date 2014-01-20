#ifndef DATE_H
#define DATE_H

#include <QtCore/qdatetime.h>
#include <iostream>
#include <string.h>

using namespace std;

class Date
{

public:
    Date();

    QDateTime getDateTimeObject();
    QDate getCurrentDate();
    QTime getCurrentTime();
    QDate getDateFromString(string &date);
    QTime getTimeFromString(string &time);
    string getStringFromDate(QDate &date);
    string getStringFromTime(QTime &time);
    int getDaysInMonth(QDate &date);

};

#endif // DATE_H
