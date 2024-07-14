/*
A Transmission is purchased from Aztec Inc., and must be inventoried. There are 25 of
them, with 10 more on reorder. Their price is $1789.98. Instantiate and initialize an
object for Transmission, and provide the same information.
*/

#include <iostream>
#include <cstring>

using namespace std;

class Inventory {
    int quant;     // number on hand
    int reorder;   // reorder quantity
    double price;  // price per unit
    char *descrip; // description of item
    public:
        Inventory(){}
        Inventory(int q, int r, double p, char *d) : quant(q), reorder(r), price(p){
            descrip = new char[strlen(d) + 1];
            strcpy(descrip, d);
        }
        ~Inventory(){
            delete[] descrip;
        };
        void print(){
            cout<< "Quantity: " << quant << endl;
            cout << "Reorder: " << reorder << endl;
            cout << "Price: " << price << endl;
            cout << "Description: " << descrip << endl;
        }
};

class Auto : public Inventory {
    char * manufacturer;
    public:
        Auto (int q, int r, double p, char * d, char * man) : Inventory(q, r ,p, d){
            manufacturer = new char[strlen(man) + 1];
            strcpy(manufacturer, man);
        }
        ~Auto(){
            delete[] manufacturer;
        }

        void print(){
            Inventory :: print();
            cout << "Manufacturer: " << manufacturer << endl;
        }
};

class Transmission : public Inventory {
    char * vendor;
    public:
        Transmission (int q, int r, double p, char * d, char * ven) : Inventory(q, r, p, d){
            vendor = new char[strlen(ven) + 1];
            strcpy(vendor, ven);
        }
        ~ Transmission(){
            delete[] vendor;
        }
        void print(){
            Inventory :: print();
            cout << "Vendor: " << vendor << endl;
        };
};

int main(){
    char desc[] = "Purchased from Aztec Inc.";
    char ven[] = "Aztec Inc.";
    Transmission trans(25, 10, 1789.98 , desc, ven);
    trans.print();
    return 0;
}