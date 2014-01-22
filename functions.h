#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>


using namespace std;

int createRandomValue(int range, int startingPoint);
int getIntegerFromConsole();
string getStringFromConsole();
int convertStringToInt(string _str);
int mainMenu();
int menuLogged();
int menuShowCalendar();
int menuShowEvents();
void loggedAs();


#endif // FUNCTIONS_H
