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


//ustawienie wprowadzonej daty przy wprowadzaniu osobno dnia, miesiaca i roku
void Date::setDate( int day, int month, int year )
{
    QDate data(year,month,day);
    dateAndTimeObject.setDate(data);
}

//ustawianie czasu przy wprowadzaniu osobno godziny, minuty i sekundy
void Date::setTime( int hour, int minutes, int seconds )
{
    QTime czas(hour,minutes,seconds);
    dateAndTimeObject.setTime(czas);
}
// zamiana qdate > string
string Date::getStringFromDate(const QDate &date)
{
    QString tmpString = date.toString("dd-MM-yyyy");
    string dateString = tmpString.toStdString();

    return dateString;
}

int Date::getDaysInMonth()
{
    return dateAndTimeObject.date().daysInMonth();
}

QDateTime Date::addDays(int days)
{
   QDateTime tmp;
    tmp = dateAndTimeObject.addDays(days);
    return tmp;
}

void Date::ImportDateAndTimeFromString(string _str)
{
    QString qstr(_str.c_str());
    dateAndTimeObject =  QDateTime::fromString(qstr,"dd-MM-yyyyhh:mm");
}

string Date::ExportDateAndTimeToString()
{
    return dateAndTimeObject.toString("dd-MM-yyyyhh:mm").toStdString();
}
