#include<iostream>
#include<cstring>

using namespace std;

class String{
    char* text;
    int length;

    public:
        String(char t[]){
            strcpy(text, t);
            length = strlen(t);
        }

        String(){};

        String operator+(String &o){
            int l = length + o.length;
            char *t = new char(l);
            strcat(t, text);
            strcat(t, o.text);

            String result(t);
            delete[] t;
            return result;
        }

        void operator=(String &o){
            strcpy(text, o.text);
            length = o.length;
        }

        bool operator == (String &o){
            return(strcmp(text, o.text));
        }
}