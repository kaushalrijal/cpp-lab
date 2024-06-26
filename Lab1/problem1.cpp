#include <iostream>

using namespace std;

class DISTANCE
{
private:
    int feet;
    int inches;

public:
    void input_distance()
    {
        cout << "Enter the distance(feet and inches): ";
        cin >> feet >> inches;
    }

    void output_distance()
    {
        cout << "Feet: " << feet << "\t Inches: " << inches;
    }

    DISTANCE add(DISTANCE d2)
    {
        DISTANCE d;
        d.feet = feet + d2.feet;
        d.inches = inches + d2.inches;
        if (d.inches > 12)
        {
            d.feet++;
            d.inches %= 12;
        }

        return d;
    }
};

int main()
{
    DISTANCE d1, d2, sum;
    cout << "Input distance 1" << endl;
    d1.input_distance();
    cout << "Input distance 2" << endl;
    d2.input_distance();

    sum = d1.add(d2);

    cout << "The sum of the distances is:" << endl;
    sum.output_distance();

    return 0;
}