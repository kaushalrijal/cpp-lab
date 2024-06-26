/*
Modify class in the previous program to work with compile time memory allocation i.e. with char[].
*/

#include<iostream>
#include<cstring>

#define MAX_SIZE 100

using namespace std;

class String{
    char text[MAX_SIZE];
    int length;

    public:
        String(char t[]){
            length = strlen(t);
            strcpy(text, t);
        }

        String(){};

        String operator+(String s2){
            String t;
            strcpy(t.text, text);
            strcat(t.text, s2.text);
            return t;
        }

        void operator=(String t){
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