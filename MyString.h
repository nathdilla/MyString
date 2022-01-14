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
    void ensureCapacity(int c);
public:
    MyString();//default constructor
    MyString(string s);//constructor that takes string
    MyString(const MyString& m);//copy constructor
    int length();//return the length of the array
    string toString();
    MyString concat(MyString s);
    int compareTo(MyString);
    char get(int c);
};


#endif //MYSTRING_MYSTRING_H
