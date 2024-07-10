// Overload >> and << operators to input and display time.
#include<iostream>

using namespace std;

class Time {
    int hr, min, sec;

public:
    friend ostream& operator<<(ostream &, Time &);
    friend istream& operator>>(istream &, Time &);
};

ostream &operator<<(ostream &out, Time &t) {
    out << t.hr << ":" << t.min << ":" << t.sec; 
    return out;
}

istream &operator>>(istream &in, Time &t) {
    in >> t.hr >> t.min >> t.sec;
    return in;
}

int main() {
    Time t;
    cout << "Enter time in format HH MM SS: ";
    cin >> t;
    cout << "You entered: " << t << endl;
    return 0;
}