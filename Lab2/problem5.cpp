/*
Create a 'STRING' class which char* and length as data member and overloads ‘+’ ,’=’ and ‘ = = ‘ to perform respective operations.
Use constructor and destructor whenever suitable.
*/

#include<iostream>
#include<cstring>

using namespace std;

class String{
    char* text;
    int length;

    public:
        String(char t[]){
            length = strlen(t);
            text = new char[length + 1];
            strcpy(text, t);
        }

        String(){};

        ~String(){
            delete[] text;
        }

        String operator+(String s2){
            String t;
            t.text = new char[length + s2.length + 1];
            strcpy(t.text, text);
            strcat(t.text, s2.text);
            return t;
        }

        void operator=(String t){
            text = new char[strlen(t.text)+1];
            strcpy(text, t.text);
        }

        bool operator == (String &o){
            return(!strcmp(text, o.text));
        }

        void display(){
            cout << text << endl;
        }
};

int main(){
    String str1("hello");
    String str2("world");
    String str3 = str1 + str2;
    String str4("helloworld");

    if(str3 == str4){
        cout << "yes it's working" << endl;
        str3.display();
    } else {
        cout << "Not working" << endl;
        str3.display();
        str4.display();
    }

    return 0;
}