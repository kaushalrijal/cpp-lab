/*
Modify Q.2 to add base class sales that holds an array of three
floats so that it can record the dollar sales of a particular
publication for the last three months. Include getdata() function
to get three Sales amount from the user and a putdata() function to
display sales figures. Alter the book and tape classes so they are
derived from both publication and sales. An object of class book or
tape should input and output sales data along with its other data.
*/

#include<iostream>
#include<iomanip>

using namespace std;

class Publication{
    string title;
    float price;

    public:
        void getData(){
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter price: ";
            cin >> price;
        }

        void putData(){
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
        }
};

class Sales {
    float a[3];

    public:
        void getData(){
            cout << "Enter the sales for each of last three months: ";
            for(int i=0; i<3; i++){
                cin >> a[i];
            }
        }

        void putData(){
            cout << "Sales of last three months: ";
            for(int i=0; i<3; i++){
                cout << a[i] << setw(5);
            }
            cout << endl;
        }
};


class Book : public Publication, Sales {
    int pageCount;

    public:
        void getData(){
            Publication :: getData();
            Sales :: getData();
            cout << "Enter the page count: ";
            cin >> pageCount;
        }

        void putData(){
            Publication :: putData();
            Sales :: putData();
            cout << "Page count: " << pageCount << endl;
        }
};

class Tape : public Publication, Sales {
    int playingTime;

    public:
        void getData(){
            Publication :: getData();
            Sales :: getData();
            cout << "Enter the playing time in hours: ";
            cin >> playingTime;
        }

        void putData(){
            Publication :: putData();
            Sales :: putData();
            cout << "Playing time: " << playingTime << endl;
        }
};

int main(){
    Book b;
    Tape t;

    cout << "Enter book details:" << endl;
    b.getData();
    cout << "Enter tape details:" << endl;
    t.getData();

    cout << endl;
    b.putData();
    cout << endl;
    t.putData();

    return 0; 
}