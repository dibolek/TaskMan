#include "date.h"

Date::Date()
{
    mainDate = QDateTime(QDate::currentDate(),QTime::currentTime());
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
    mainDate.setDate(data);
}

//zwracanie aktualnego czasu
QTime Date::getCurrentTime()
{
    QTime time = QTime::currentTime();

    return time;
}

//ustawianie czasu przy wprowadzaniu osobno godziny, minuty i sekundy
void Date::setTime( int hour, int minutes, int seconds )
{
    QTime czas(hour,minutes,seconds);
    mainDate.setTime(czas);
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

int Date::getDaysInMonth(QDate &date)
{
    return date.daysInMonth();
}

QDateTime Date::getMainDate()
{
    return mainDate;
}
