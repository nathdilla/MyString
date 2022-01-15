//
// Created by Nathan Dilla on 1/13/22.
//
#include <string>
#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H
using namespace std;

class MyString {
private:
    int capacity;
    int curr_length;
    char* words;
    void ensureCapacity();
public:
    MyString();//default constructor
    MyString(string s);//constructor that takes string
    MyString(MyString&);//copy constructor
    int length();//return the length of the array
    string toString();
    MyString concat(MyString&);
    bool equals(MyString&);
    int compareTo(MyString&);
    char get(int c);
    MyString toUpper();
    MyString toLower();
    MyString substring(int sub);
    MyString substring(int l, int u);
    int indexOf(MyString&);
    int lastIndexOf(MyString&);
};


#endif //MYSTRING_MYSTRING_H
