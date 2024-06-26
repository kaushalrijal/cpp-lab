// To write a C++ program to manipulate complex numbers using operator overloading. (addition,subtraction,multiplication,division)

#include<iostream>

using namespace std;

class Complex {
    float real;
    float img;

    public:
        void input(){
            cin >> real >> img;
        }

        void output(){
            if(img < 0){
                cout << real << img << "i";
            } else {
                cout << real << "+" << img << "i";
            }
        }
        // Overloading the addition operator
        Complex operator+(Complex &other){
            Complex c;
            c.real = real + other.real;
            c.img = img + other.img;
            return c;
        }
        // Overloading the subtraction operator
        Complex operator-(Complex &other){
            Complex c;
            c.real = real - other.real;
            c.img = img - other.img;
            return c;
        }
        // Overloading the multipication operator
        Complex operator*(Complex &other){
            Complex c;
            c.real = real * other.real - img * other.img;
            c.img = real * other.img + img * other.real;
            return c;
        }
        // Overloading the division operator
        Complex operator/(Complex &other){
            Complex c;
            float denom = other.real * other.real + other.img * other.img;
            c.real = (real * other.real + img * other.img) / denom;
            c.img = (img * other.real - real * other.img) / denom;
            return c;
        }
};

int main(){
    Complex c1, c2, sum, diff, prod, quo;
    cout << "Enter the real and imaginary part of the first number: ";
    c1.input();
    cout << "Enter the real and imaginary part of the second number: ";
    c2.input();

    sum = c1 + c2;
    diff = c1 - c2;
    prod = c1 * c2;
    quo = c1 / c2;

    c1.output();
    cout<< " + ";
    c2.output();
    cout << " = ";
    sum.output();

    cout << endl;
    c1.output();
    cout<< " - ";
    c2.output();
    cout << " = ";
    diff.output();

    cout << endl;
    c1.output();
    cout<< " * ";
    c2.output();
    cout << " = ";
    prod.output();

    cout << endl;
    c1.output();
    cout<< " / ";
    c2.output();
    cout << " = ";
    quo.output();


    return 0;
}