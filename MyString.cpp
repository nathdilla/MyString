//
// Created by Nathan Dilla on 1/13/22.
//

#include "MyString.h"
#include <iostream>

void MyString::ensureCapacity(int c)
{
    char* temp = new char[curr_length];
    for(int i=0;i<curr_length;i++)
    {
        temp[i]=words[i];
        delete words;
        curr_length=curr_length+c;
        words=new char[curr_length];
        capacity=sizeof (words)/sizeof (words[0]);
    }

}
MyString::MyString()//default constructor
{
    words=NULL;
    curr_length=0;
}
MyString::MyString(string s)//constructor that takes string
{
    curr_length=s.length();
    words=new char[curr_length];
    for(int i=0;i<curr_length;i++)
    {
        words[i]=s.at(i);
    }
    capacity=sizeof (words)/sizeof (words[0]);
}
MyString::MyString(const MyString& m)//copy constructor
{
    capacity=m.capacity;
    curr_length=m.curr_length;
    for(int i=0;i<curr_length;i++)
    {
        words[i]=m.words[i];
    }
}
int MyString::length()//return the length of the array
{
    return curr_length;
}
string MyString::toString()
{
    string res="";
    for(int i=0;i<curr_length;i++)
    {
        res=res+words[i];
    }
    return res;
}
MyString MyString::concat(MyString s)
{
    cout<<"g";
//    ensureCapacity(s.length());
//    MyString newStr();
//    for(int i=0; i<s.length();i++)
//    {
//        words[curr_length-s.length()+i]=s.get(i);
//    }
//    return MyString("bruh");
}
int MyString::compareTo(MyString)
{
    return 0;
}
char MyString::get(int c)
{
    return words[c];
}
