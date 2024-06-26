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