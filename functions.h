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
bool integerCin(int &integer);
int convertStringToInt(string _str);
void pause();
void clearScreen();

int mainMenu();
int menuLogged();
int menuShowCalendar();
int menuShowEvents();
void loggedAs();
int menuAddEvent();

#endif // FUNCTIONS_H
