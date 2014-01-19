#include "functions.h"

int createRandomValue(int range, int startingPoint)
{
    return ( rand()% range + startingPoint );
}

int getIntegerFromConsole()
{
    int x;
    cin>>x;
    return x;
}

string getStringFromConsole()
{
    string tmp;
    getline(cin,tmp);
    return tmp;
}

