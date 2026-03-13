#include <iostream>
#include <cstdio>
using namespace std;

class date
{
    int day, month, year;

public:
    date(char *str) // mandatory
    {
        sscanf(str, "%d/%d/%d", &day, &month, &year);
    }
    date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void show()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

// date::date(char *str)

int main()
{
    date sdate("31/12/99");
    date idate(31, 12, 99);
    sdate.show();
    idate.show();
}