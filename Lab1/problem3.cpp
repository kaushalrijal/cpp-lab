/*
Write a program that checks the order of a medicine from a pharmacy store.
The program should read the order quantity and the medicine quantity in the
store. When the order quantity is more than the store quantity, your
program should display the message “No enough quantity”. When the order
quantity is less than the store quantity, you have to check that the order
quantity must be not more than 16 except there is more than 40 items in the
store. The messages that will be displayed in that cases are “Your order is
accepted” OR “You cannot order more than 16 item”
*/
#include <iostream>

using namespace std;

int main()
{
    int store_qnt, order_qnt;
    cout << "Enter the store quantity: ";
    cin >> store_qnt;
    cout << "Enter the order quantity: ";
    cin >> order_qnt;

    if (order_qnt > store_qnt)
    {
        cout << "No enough quantity";
    }
    else if (order_qnt > 16)
    {
        cout << "You cannot order more than 16 item";
    }
    else
    {
        cout << "Your order is accepted";
    }
}