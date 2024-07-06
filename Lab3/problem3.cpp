// Program to convert Cartesian coordinate to Polar.

#include<iostream>
#include<cmath>

using namespace std;

class polar{
    float rad, ang;

    public:
        polar(){}
        polar(float r, float a) : rad(r), ang(a){}

        void show(){
            cout << rad << ang;
        }
};

class cartesian{
    float x, y;
    public:
        cartesian(){}
        cartesian(float xco, float yco) : x(xco), y(yco){}

        operator polar(){
            float r = sqrt(x * x + y * y);
            float a = atan(y/x);

            return polar(r, a);
        }
};

int main(){
    cartesian c(2, 3);
    polar p;

    p = c;
    p.show();
    return 0;
}