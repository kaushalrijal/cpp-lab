// To write a C++ program to swap two private data members using friend functions.

#include<iostream>

using namespace std;

class B;

class A{
    int a;
    public:
        void getNum(){
            cin >> a;
        }

        void show(){
            cout << a << endl;
        }

        friend void swap(A &, B &);
};

class B{
    int b;
    public:
        void getNum(){
            cin >> b;
        }

        void show(){
            cout << b << endl;
        }

        friend void swap(A &, B &);
};

void swap(A &aobj, B &bobj){
    int temp = aobj.a;
    aobj.a = bobj.b;
    bobj.b = temp;
}

int main(){
    A aobj;
    B bobj;
    
    cout << "Enter A: ";
    aobj.getNum();
    cout << "Enter B: ";
    bobj.getNum();

    swap(aobj, bobj);

    aobj.show();
    bobj.show();
}