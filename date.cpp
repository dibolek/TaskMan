#include "date.h"




QDateTime Date::getDateAndTimeObject() const
{
    return dateAndTimeObject;
}

void Date::setDateAndTimeObject(const QDateTime &value)
{
    dateAndTimeObject = value;
}

void Date::setCurrentDateAndTime()
{
    dateAndTimeObject = QDateTime::currentDateTime();
}

Date::Date()
{
    dateAndTimeObject = QDateTime(QDate::currentDate(),QTime::currentTime());
}

// zwracanie aktualnej daty
QDate Date::getCurrentDate()
{
    QDate date  = QDate::currentDate();

    return date;
}

//ustawienie wprowadzonej daty przy wprowadzaniu osobno dnia, miesiaca i roku
void Date::setDate( int day, int month, int year )
{
    QDate data(year,month,day);
    dateAndTimeObject.setDate(data);
}

void Date::setDateFromString(string &date)
{
    QString dateString = QString::fromStdString(date);
    QDate dateFromString = QDate::fromString(dateString,"dd-MM-yyyy");
    dateAndTimeObject.setDate(dateFromString);
}

// zamiana string > qtime
void Date::setTimeFromString(string &time)
{
    QString timeString = QString::fromStdString(time);
    QTime timeFromString = QTime::fromString(timeString,"hh:mm");
    dateAndTimeObject.setTime(timeFromString);
}

//zwracanie aktualnego czasu
QTime Date::getCurrentTime()
{
    QTime time = QTime::currentTime();

    return time;
}

//ustawianie czasu przy wprowadzaniu osobno godziny, minuty i sekundy
void Date::setTime( int hour, int minutes )
{
    QTime czas(hour,minutes,0);
    dateAndTimeObject.setTime(czas);
}

// zamiana string > qdate
QDate Date::getDateFromString(string &date)
{
    QString dateString = QString::fromStdString(date);
    QDate dateFromString = QDate::fromString(dateString,"dd-MM-yyyy");

    return dateFromString;
}

// zamiana string > qtime
QTime Date::getTimeFromString(string &time)
{
    QString timeString = QString::fromStdString(time);
    QTime timeFromString = QTime::fromString(timeString,"hh:mm");

    return timeFromString;
}

// zamiana qdate > string
string Date::getStringFromDate(const QDate &date)
{
    QString tmpString = date.toString("dd-MM-yyyy");
    string dateString = tmpString.toStdString();

    return dateString;
}

// zamiana qtime > string
string Date::getStringFromTime(QTime &time)
{
    QString tmptime = time.toString("hh:mm");
    string timeString = tmptime.toStdString();

    return timeString;
}

int Date::getDaysInMonth()
{
    return dateAndTimeObject.date().daysInMonth();
}



void Date::ImportDateAndTimeFromString(string _str)
{
    QString qstr(_str.c_str());
    dateAndTimeObject =  QDateTime::fromString(qstr,"dd-MM-yyyyhh:mm");
}

string Date::ExportDateAndTimeToString()
{
    return dateAndTimeObject.toString("dd-MM-yyyyhh:mm").toStdString();
//    return _qdt.toString("dd-MM-yyyyhh:mm").toStdString();
}
