#include "date.h"

Date::Date()
{
}

// zwracanie aktualnej daty
QDate Date::getCurrentDate()
{
    QDate date  = QDate.currentDate();

    return date;
}

//zwracanie aktualnego czasu
QTime Date::getCurrentTime()
{
    QTime time = QTime.currentTime();

    return time;
}

// zamiana string > qdate
QDate Date::getDateFromString(string date)
{
    QString dateString = QString.fromStdString(date);
    QDate dateFromString = QDate.fromString(dateString,"dd-MM-yyyy");

    return dateFromString;
}

// zamiana string > qtime
QTime Date::getTimeFromString(string time)
{
    QString timeString = QString.fromStdString(time);
    QTime timeFromString = QTime.fromString(timeString,"hh:mm");

    return timeFromString;
}

// zamiana qdate > string
string Date::getStringFromDate(QDate date)
{
    QString tmpString = date.toString("dd-MM-yyyy");
    string dateString = tmpString.toStdString();

    return dateString;
}

// zamiana qtime > string
string Date::getStringFromTime(QTime time)
{
    QString tmptime = time.toString("hh:mm");
    string timeString = tmptime.toStdString();

    return timeString;
}

int Date::getDaysInMonth(QDate date)
{
    return date.daysInMonth();
}
