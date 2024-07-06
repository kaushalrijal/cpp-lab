// Program to convert time (hour, minute and second) in 24-hr format to 12-hr format.

#include<iostream>

using namespace std;


class TwentyFour{
    int hr, min, sec;

    public:
        TwentyFour(){}
        TwentyFour(int  h, int m, int s) : hr(h), min(m), sec(s){}

        int getH(){
            return hr;
        }

        int getM(){
            return min;
        }
        
        int getS(){
            return sec;
        }

        void show(){
            cout << hr << ":" << min << ":" << sec << endl;
        }
};

class Twelve{
    int hr, min, sec;
    string meridiam;

    public:
        Twelve(){}
        Twelve(int h, int m, int s) : hr(h), min(m), sec(s){}

        Twelve(TwentyFour &t){
            hr = t.getH() %12;
            min = t.getM();
            sec = t.getS();
            if (t.getH()>=12){
                meridiam = "PM";
            } else {
                meridiam = "AM";
            }
        }

        void show(){
            cout << hr << ":" << min << ":" << sec << " " << meridiam<<endl;
        }
};

int main(){
    TwentyFour t24(7, 4, 6);
    Twelve t12;

    t12 = t24;

    t24.show();
    t12.show();

    return 0;
}