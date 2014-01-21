#ifndef DATE_H
#define DATE_H

#include <QtCore/qdatetime.h>
#include <iostream>
#include <string.h>

using namespace std;

class Date
{
private:
    QDateTime mainDate;

public:
    Date();

    QDateTime getDateTimeObject();
    QDate getCurrentDate();
    void setDate( int day, int month, int year );
    QTime getCurrentTime();
    void setTime( int hour, int minutes, int seconds );
    QDate getDateFromString(string &date);
    QTime getTimeFromString(string &time);
    string getStringFromDate(const QDate &date);
    string getStringFromTime(QTime &time);
    int getDaysInMonth(QDate &date);
    QDateTime getMainDate();


};

#endif // DATE_H
