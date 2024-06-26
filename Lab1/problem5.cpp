#include <iostream>

using namespace std;

class Employee
{
    int id;
    string name;
    string designation;
    static int man, eng, tot;

    public:
        void input()
        {
            cin >> id >> name >> designation;
            if (designation == "MANAGER")
            {
                man++;
            }
            if (designation == "ENGINEER")
            {
                eng++;
            }
            tot++;
        }

        void display_count()
        {
            cout << "Total Employees: " << tot << endl;

            cout << "Managers: " << man << endl;

            cout << "Engineers: " << eng << endl;
        }
};

int Employee::man = 0;
int Employee::eng = 0;
int Employee::tot = 0;

int main()
{
    Employee e[100];
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter employee id, name and designation: ";
        e[i].input();
    }

    e[0].display_count();

    return 0;
}
