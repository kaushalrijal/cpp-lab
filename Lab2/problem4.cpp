/*
Create a class called 'TIME' that has
- three integer data members for hours, minutes and seconds
- constructor to initialize the object to zero
- constructor to initialize the object to some constant value
- overload +,- to add and subtract two TIME objects
- overload > function to compare two time
- member function to display time in HH:MM:SS format
*/

#include<iostream>

using namespace std;

class Time{
    int hour;
    int min;
    int sec;

    public:
        Time(){
            hour=0;
            min = 0;
            sec = 0;
        }
        Time(int h, int m, int s){
            hour = h;
            min = m;
            sec = s;
        }

        void display(){
            cout << hour << ":" << min << ":" << sec << endl;
        }

        Time operator+(Time &o){
            Time t;
            t.hour = hour + o.hour;
            t.min = min + o.min;
            t.sec = sec + o.sec;

            t.min += t.sec/60;
            t.sec %= 60;
            t.hour += t.min/60;
            t.min%=60;
            return t;
        }

        Time operator-(Time &o){
            Time t;

            t.sec = hour * 3600 + min * 60 + sec - (o.hour * 3600 + o.min * 60 + o.sec);
            t.min = t.sec/60;
            t.sec %= 60;
            t.hour = t.min / 60;
            t.min %= 60;
            return t;
        }

        bool operator>(Time &o){
            if (hour > o.hour)
                return true;
            if(min > o.min)
                return true;
            if(sec > o.sec)
                return true;
        
            return false;
        }
};

int main(){
    Time t1(1,20,0), t2(1, 40, 0), t;
    t = t1 + t2;
    t = t1 - t2;
    t.display();
    cout << (t1 > t2);
    return 0;
}