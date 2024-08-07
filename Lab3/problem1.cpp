/*
Program to convert Nepalese Currency (Rupees and Paisa) to US Currency (Dollar and Cents). (Rs. 98.51=1$)
*/

#include<iostream>

using namespace std;

class Rupees{
    int rupee, paisa;

    public:
        Rupees(int ru, int pa){
            rupee=ru;
            paisa=pa;
        }

        int getRupees(){
            return rupee;
        }
        
        int getPaisa(){
            return paisa;
        }

        void show(){
            cout << "Rs." << rupee << "." << paisa;
        }
};

class Dollars{
    int dollar, cent;
    public:
        Dollars(){}
        Dollars(Rupees r){
            float totalRupees = static_cast<float>(r.getPaisa())/100 + r.getRupees();
            float totalDollars = totalRupees / 98.51;
            dollar = static_cast<int>(totalDollars);
            cent = (totalDollars-dollar) * 100;
        }

        void show(){
            cout << "$" << dollar << "."<< cent;
        }

};

int main(){
    Rupees r(98,51);
    Dollars d;
    d = r;
    cout << "Amount in rupes: ";
    r.show();
    cout << endl;
    cout << "Amount in dollars: ";
    d.show();
    return 0;
}
