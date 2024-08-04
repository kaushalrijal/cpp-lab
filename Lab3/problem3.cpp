// Program to convert Cartesian coordinate to Polar.

#include <iostream>
#include <cmath>

using namespace std;

class polar {
    float rad, ang;

public:
    polar() : rad(0), ang(0) {}
    polar(float r, float a) : rad(r), ang(a) {}

    void show() {
        cout << "Radius: " << rad << ", Angle: " << ang << " radians" << endl;
    }
};

class cartesian {
    float x, y;

public:
    cartesian() : x(0), y(0) {}
    cartesian(float xco, float yco) : x(xco), y(yco) {}

    operator polar() {
        float r = sqrt(x * x + y * y);
        float a = atan2(y, x); // Use atan2 for correct angle calculation

        return polar(r, a);
    }
};

int main() {
    cartesian c(2, 3);
    polar p;

    p = c;
    p.show();
    return 0;
}