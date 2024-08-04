// Program to convert time (hour, minute and second) in 12-hr format to 24-hr format.

#include <iostream>
#include <string>

using namespace std;

class TwentyFour;

class Twelve
{
    int hr, min, sec;
    string meridiam;

public:
    Twelve() {}
    Twelve(int h, int m, int s, string me) : hr(h), min(m), sec(s), meridiam(me) {}

    operator TwentyFour();

    void show()
    {
        cout << (hr < 10 ? "0" : "") << hr << ":"
        << (min < 10 ? "0" : "") << min << ":"
        << (sec < 10 ? "0" : "") << sec << " "
        << meridiam << endl;
    }
};

class TwentyFour
{
    int hr, min, sec;

public:
    TwentyFour() {}
    TwentyFour(int h, int m, int s) : hr(h), min(m), sec(s) {}

    int getH()
    {
        return hr;
    }

    int getM()
    {
        return min;
    }

    int getS()
    {
        return sec;
    }

    void show()
    {
        cout << (hr < 10 ? "0" : "") << hr << ":"
        << (min < 10 ? "0" : "") << min << ":"
        << (sec < 10 ? "0" : "") << sec << endl;
    }
};

Twelve::operator TwentyFour()
{
    if (meridiam == "AM")
    {
        return TwentyFour(hr, min, sec);
    }
    else
    {
        if (hr == 12)
        {
            return TwentyFour(hr, min, sec);
        }
        else
        {
            return TwentyFour(hr + 12, min, sec);
        }
    }
}

int main()
{
    TwentyFour t24;
    Twelve t12(7, 8, 9, "PM");

    t24 = t12;

    cout << "12 hours format: ";
    t12.show();
    cout << "24 hours format: ";
    t24.show();

    return 0;
}