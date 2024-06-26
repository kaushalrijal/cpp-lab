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
    cin >> r >> d;
    rupees r1(r);
    dollars d1(d);
    
    cout << (d1 > r1);
    cout << (r1 > d1);
}