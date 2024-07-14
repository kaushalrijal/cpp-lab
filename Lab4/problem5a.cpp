/*
Write a main () function that creates an instance object of Auto called Car, which has the
following initial data: there is a quantity of five(5) on inventory, and two(2) on reorder;
the price per unit is $15,545.91, and the description is that of the car obtained from the
Toyota. Initialize the object Car, and print out all its vital facts.
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
            descrip = new char[sizeof(d) + 1];
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
    char desc[] = "Obtained from toyota";
    char man[] = "Toyota";
    Auto car(5, 2, 15545.91, desc, man);
    car.print();
    return 0;
}