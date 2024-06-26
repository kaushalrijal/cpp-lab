#include<iostream>

using namespace std;

class Variables{
    int x,y;

    public:
        void init(){
            cout << "Enter the value of x and y: ";
            cin >> x >> y;
        }

        void display(){
            cout << "x:" << x << "\t y:" << y << endl;
        }

        friend void swap(Variables &v1);
};

void swap(Variables &v1){
    int temp = v1.x;
    v1.x = v1.y;
    v1.y = temp;
}

int main(){
    Variables v;
    cout << "Enter x and y: ";
    v.init();
    cout << "Before swapping: " << endl;
    v.display();

    swap(v);
    cout << "After swapping:" << endl;
    v.display();

    return 0;
}