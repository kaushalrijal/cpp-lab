/*
    Assume class person stores the Name, Age and ID, class employee
    stores the designation, basic salary, total overtime(hr) in a month
    and hourly rate and class computedSalary stores the total salary of
    the employee. Implement above concept using appropriate inheritance
*/

#include<iostream>

using namespace std;

class Person {
    char name[30];
    int age;
    int id;

    public:
        void getData(){
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter id: ";
            cin >> id;
        }

        void showData(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Id: " << id << endl;
        }
};

class Employee : public Person{
    char designation[30];

    protected:
        float basicSal;
        int totOvertime;
        int hourlyRate;

    public:
        void getData(){
            Person::getData();
            cout << "Enter employee designation: ";
            cin >> designation;
            cout << "Enter the basic salary: ";
            cin >> basicSal;
            cout << "Enter the total overtime in a month in hours: ";
            cin >> totOvertime;
            cout << "Enter the hourly rate: ";
            cin >> hourlyRate;
        }

        void showData(){
            Person :: showData();
            cout << "Designation: " << designation << endl;
            cout << "Basic Salary: " << basicSal << endl;
        }
};

class ComputedSalary : public Employee {
    float totalSal;

    public:
        void getData(){
            Employee :: getData();
            calculate();
        }

        void calculate(){
            totalSal = basicSal + totOvertime * hourlyRate;
        }

        float getTotal(){
            return totalSal;
        }

        void showData(){
            Employee :: showData();
            cout << "Total Salary: " << totalSal << endl;
        }
};

int main(){
    ComputedSalary total;
    total.getData();
    cout << endl;
    total.showData();
    return 0;
}