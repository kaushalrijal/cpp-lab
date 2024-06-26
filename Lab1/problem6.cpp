// To write a C++ program to add two private data members using friend functions.

#include<iostream>

using namespace std;

class Complex{
    float real;
    float imag;

    public:
        void input(){
            cin >> real >> imag;
        }

        void output(){
            cout << real << "+i" << imag;
        }

        friend Complex add (Complex, Complex);
};

Complex add (Complex c1, Complex c2){
    Complex c;
    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;
    return c;
}

int main(){
    Complex c1, c2, c;

    cout << "Enter the real and imaginary part of the first number: ";
    c1.input();
    cout << "Enter the real and imaginary part of the second number: ";
    c2.input();

    c = add(c1, c2);

    c.output();
    return 0;

}