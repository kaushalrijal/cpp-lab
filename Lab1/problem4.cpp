#include <iostream>

using namespace std;

class Employee
{
    int empno;
    string name;
    float basic;
    float DA, IT, net_sal;

public:
    void input()
    {
        cin >> empno >> name >> basic;
        calculate();
    }

    void output()
    {
        cout << "Employee No.: " << empno << endl;
        cout << "Name" << name << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "Daily Allowance: " << DA << endl;
        cout << "Income Tax: " << IT << endl;
        cout << "Net Salary: " << net_sal << endl;
    }

    void calculate();
};

void Employee::calculate()
{
    DA = 0.52 * basic;
    float gross_sal = basic + DA;
    IT = 0.3 * gross_sal;
    net_sal = gross_sal - IT;
}

int main()
{
    Employee e;
    cout << "Enter the employee no, name and basic salary: ";
    e.input();

    e.output();
}