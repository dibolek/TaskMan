#ifndef DATE_H
#define DATE_H

#include <QtCore/qdatetime.h>
#include <iostream>
#include <string.h>

using namespace std;

class Date
{
private:
    QDateTime dateAndTimeObject;

public:
    Date();

    void setDate( int day, int month, int year );
    void setTime(int hour, int minutes, int seconds);
    void setCurrentDateAndTime();
    void setDateFromString(string &date);
    void setTimeFromString(string &time);
    QDate getDateFromString(string &date);
    QTime getTimeFromString(string &time);
    string getStringFromDate(const QDate &date);
    string getStringFromTime(QTime &time);
    int getDaysInMonth();
    QDateTime addDays(int days);

    void ImportDateAndTimeFromString(string _str);
    string ExportDateAndTimeToString();


    QDateTime getDateAndTimeObject() const;
    void setDateAndTimeObject(const QDateTime &value);
};

#endif // DATE_H
