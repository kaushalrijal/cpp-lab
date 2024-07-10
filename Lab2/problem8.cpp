/*
A parking garage charges a $2.00 minimum fee to park for up to three hours. The garage charges an additional
$0.50 per hour for each hour or part thereof in excess of three hours. People who park their cars for longer
than 24 hours will pay $8.00 per day. Write a program that calculates and prints the parking charges. The inputs
to your program are the date and time when a car enters the parking garage, and the dateand time when the same car
leaves the parking garage. Keep track of number of cars in the garage overloading ++ and -- operators.
*/

#include<iostream>
#include<conio.h>

#define size 15

using namespace std;

class DateTime{
    int hr, min, sec;
    public:
        void inputTime(){
            cin >> hr >> min >> sec;
        }
        int getHour(){
            return hr;
        }
        DateTime operator-(DateTime &o){
            DateTime t;

            t.sec = hr * 3600 + min * 60 + sec - (o.hr * 3600 + o.min * 60 + o.sec);
            t.min = t.sec/60;
            t.sec %= 60;
            t.hr = t.min / 60;
            t.min %= 60;
            return t;
        }
};

class garage{
    bool isVacant = true;
    DateTime inTime;
    DateTime outTime;
    DateTime diff;
    int days;
    string id;
    static int count;

    public:
        void park(){
            cout << "Enter the enter time(hour, minute and seconds): ";
            inTime.inputTime();
            cout << "Enter the vehicle id: ";
            cin >> id;
            isVacant = false;
            cout << "Car parked successfully";
            count ++;
        }

        void leave(){
            cout << "Enter the exit time(hour, minute and seconds): ";
            outTime.inputTime();
            cout << "Enter the days stayed: ";
            cin >> days;
            isVacant = true;
            calculate();
        }

        void calculate(){
            diff = outTime - inTime;
            int hrs = diff.getHour();
            float totalfee;
            if(hrs < 0 && days ==0){
                cout << "Invalid Time enterd. Please try again." << endl << endl;
                leave();
            } else {
                if(hrs <= 3){
                    totalfee = 2;
                } else if (days == 0){
                    totalfee = 2 + 0.5 * (hrs - 3);
                } else {
                    totalfee = 8 * days;
                }

                cout << "Your total is $" << totalfee << endl;
                cout << "Thanks for letting us serve you. Looking forward to help you again soon." << endl << endl;
                id = "";
                days = 0;
                count --;
            }
        }

        bool isFree(){
            return isVacant;
        }

        string getId(){
            return id;
        }

        int getCount(){
            return count;
        }

        void operator++(){
            count++;
        }

        void operator--(){
            count--;
        }
};

int garage::count = 0;

void input(garage p[]){
    int flag = 1;
    for(int i=0; i<size; i++){
        if(p[i].isFree()){
            p[i].park();
            p++;
            flag = 0;
            break;
        } 
    }
    if(flag){
        cout << "Not enough space" << endl;
    }
}

void leave(garage p[]){
    string vid;
    int flag=1;
    cout << "Enter the vehicle id: ";
    cin >> vid;
    for(int i=0; i<size; i++){
        if(vid == p[i].getId()){
            p[i].leave();
        }
    }

    if(flag){
        cout << "Sorry vehicle not found" << endl;
    }
}

int main(){
    garage g[size];
    int ch;
    char h;
    while(1){
        system("cls");
        cout << "Welcome to the garage." << endl;
        cout << "1) Enter a car" << endl;
        cout << "2) Leave car" << endl;
        cout << "3) Exit program" << endl;

        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                input(g);
                break;
            case 2:
                leave(g);
                break;
            case 3:
                return 0;
            default:
                cout << "Bad choice. Press any key to continue...";
        }
        cout << "Press any key to continue...";
        getch();
    }
}