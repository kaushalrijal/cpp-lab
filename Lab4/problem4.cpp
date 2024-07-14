/*

*/

#include <iostream>

using namespace std;

class Date {
    int day, month, year;

    public:
        Date(int d, int m, int y) : day(d), month(m), year(y){}
        ~Date(){};
        void display(){
            cout << year << "/" << month << "/" << day << endl;
        }; // displays the date
        Date get(){
            return *this;
        };     // accesses the date members
        void set(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }     // sets the date members
};

class Time {
    int hour;
    int minute;
    int second;

    public:
        Time(int h, int m, int s) : hour(h), minute(m), second(s){}
        ~Time(){};
        void display(){
            cout << hour << ":" << minute << ":" << second << endl;
        } 
        Time get(){
            return *this;
        };     // accesses the time members
        void set(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        };     // sets the time members
};

class DateAndTime : public Date, public Time {
    public:
        DateAndTime(int d, int m, int y, int h, int min, int s) : Date(d, m, y) , Time(h, min, s){}

        void display(){
            Date :: display();
            Time :: display();
        }; // prints date and time
};

int main(){
    DateAndTime Watch(14, 7, 2024, 01, 19, 55);
    cout << "Before resetting:" << endl;
    Watch.display();
    Watch.Date::set(21, 5, 2024);
    Watch.Time::set(2,30,42);
    cout << "After resetting:" << endl;
    Watch.display();
}