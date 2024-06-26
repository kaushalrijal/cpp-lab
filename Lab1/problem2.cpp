#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cout << "Enter three numbers: ";
    cin >> x >> y >> z;

    int largest = x, smallest = x;
    if (largest < y)
    {
        largest = y;
    }
    if (largest < z)
    {
        largest = z;
    }

    if (y < smallest)
    {
        smallest = y;
    }

    if (z < smallest)
    {
        smallest = z;
    }

    cout << "Largest: " << largest << "\tSmallest: " << smallest;

    return 0;
}