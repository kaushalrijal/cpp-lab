/*
To write a C++ program to overload all relational operators to compare US currency with Nepalese currency.
Use conversion rate $1=NRs 101.36(Note: make two classes to represent each currency)
*/

#include<iostream>

using namespace std;

class dollars;


class rupees{
    float amount;

    public:
        rupees(float amt){
            amount = amt;
        }

        void show(){
            cout << amount;
        }

        // Overloading all opeartors
        friend bool operator>(rupees, dollars);
        friend bool operator<(rupees, dollars);
        friend bool operator>=(rupees, dollars);
        friend bool operator<=(rupees, dollars);
        friend bool operator==(rupees, dollars);
        friend bool operator!=(rupees, dollars);
        
        friend bool operator>(dollars, rupees);
        friend bool operator<(dollars, rupees);
        friend bool operator>=(dollars, rupees);
        friend bool operator<=(dollars, rupees);
        friend bool operator==(dollars, rupees);
        friend bool operator!=(dollars, rupees);
};


class dollars{
    float amount;

    public:
        dollars(float amt){
            amount = amt;
        }

        void show(){
            cout << amount;
        }

        //Overloading all operators        
        friend bool operator>(dollars, rupees);
        friend bool operator<(dollars, rupees);
        friend bool operator>=(dollars, rupees);
        friend bool operator<=(dollars, rupees);
        friend bool operator==(dollars, rupees);
        friend bool operator!=(dollars, rupees);
        
        friend bool operator>(rupees, dollars);
        friend bool operator<(rupees, dollars);
        friend bool operator>=(rupees, dollars);
        friend bool operator<=(rupees, dollars);
        friend bool operator==(rupees, dollars);
        friend bool operator!=(rupees, dollars);
};

// Overloading for comparing rupees to dollars
bool operator>(rupees r, dollars d){
    return (r.amount > d.amount * 101.36 * 101.36);
}
bool operator<(rupees r, dollars d){
    return (r.amount < d.amount * 101.36);
}
bool operator>=(rupees r, dollars d){
    return (r.amount >= d.amount * 101.36);
}
bool operator<=(rupees r, dollars d){
    return (r.amount <= d.amount * 101.36);
}
bool operator==(rupees r, dollars d){
    return (r.amount == d.amount * 101.36);
}
bool operator!=(rupees r, dollars d){
    return (r.amount != d.amount * 101.36);
}

// Overloading for comparing dolalrs to rupees
bool operator>(dollars d, rupees r){
    return (d.amount * 101.36 > r.amount);
}
bool operator<(dollars d, rupees r){
    return (d.amount * 101.36 < r.amount);
}
bool operator>=(dollars d, rupees r){
    return (d.amount * 101.36 >= r.amount);
}
bool operator<=(dollars d, rupees r){
    return (d.amount * 101.36 <= r.amount);
}
bool operator==(dollars d, rupees r){
    return (d.amount * 101.36 == r.amount);
}
bool operator!=(dollars d, rupees r){
    return (d.amount * 101.36 != r.amount);
}

int main(){
    float r, d;
    cout << "Enter the rupee amount and dollar amount: ";
    cin >> r >> d;
    rupees r1(r);
    dollars d1(d);

    if(r1 > d1){
        cout << "Rupee amount is greater than dollar amount" << endl;
    }
    if (d1 > r1) {
        cout << "Dollar amount is greater than rupee amount" << endl;
    }
    if (d1 == r1){
        cout << "Dollar amount and rupee amount are equal" << endl;
    }
    if(r1 >= d1){
        cout << "Rupee amount is greater than or equal to dollar amount" << endl;
    }
    if (d1 >= r1) {
        cout << "Dolalr amount is greater than or equal to rupee amount" << endl;
    }
    if (d1 != r1){
        cout << "Dollar amount and rupee amount are not equal" << endl;
    }
    return 0;
}