//
// Created by Nathan Dilla on 1/13/22.
//

#include "MyString.h"
#include <iostream>

void MyString::ensureCapacity()//ensure capacity of the array and allocate more memory for more chars
{
    if(capacity==curr_length) {//if at full capacity
        char *temp = new char[capacity];//create temporary array to store current data in.
        for (int i = 0; i < curr_length; i++) {//move over current data
            temp[i] = words[i];
        }
        delete words;//reset pointer
        words = new char[capacity*2];//point to new array with double capacity
        for (int i = 0; i < curr_length; i++) {//move data from temp to new array
            words[i] = temp[i];
        }
        capacity = sizeof(words) / sizeof(words[0]);//redefine capacity
    }
}

MyString::MyString()//default constructor
{
    words=NULL;
    curr_length=0;
    capacity=0;
}
MyString::MyString(string m)//constructor that takes string
{
    curr_length=m.length();
    words=new char[curr_length];
    for(int i=0;i<curr_length;i++)
    {
        words[i]=m.at(i);
    }
    capacity=sizeof (words)/sizeof (words[0]);
}
MyString::MyString(MyString &m)//copy constructor
{
    capacity=length();
    curr_length=m.length();
    words=new char[curr_length];
    for(int i=0;i<m.length();i++)
    {
        words[i]=m.get(i);
    }
}
int MyString::length()//return the length of the array
{
    return curr_length;
}
string MyString::toString()
{
    string res="";
    for(int i=0;i<curr_length;i++)//for every char in array, concat to result
    {
        res=res+words[i];
    }
    return res;
}

MyString MyString::concat(MyString &s) {//concatenation of two MyString objs
    ensureCapacity();//make sure we have enough space
    for (int i = 0; i < s.length(); ++i) {//increment the length and add to array from passed value
        words[curr_length]=s.get(i);
        curr_length++;
        //cout<<toString()<<endl;
    };
    MyString newStr(toString());
    return newStr;
}

bool MyString::equals(MyString &s) {//boolean of if two MyString objects are the same

    if(s.length()==length())//check if they are the same length
    {
        for (int i = 0; i < s.length(); ++i) {//compare each char, if they arent equal, return false
            if(s.get(i)!= get(i))
                return false;
        }
    }
    else{
        return false;
    }
    return true;//assume they are equal
}

int MyString::compareTo(MyString &s)//compare two strings in alphabetical order
{
    int res=0;
    for (int j = 0; j < s.length(); ++j) {
        if(words[j]>s.get(j))
        {
            return 1;
        }
        else if (words[j]<s.get(j))
        {
            return -1;
        }
    }
    return res;
}
char MyString::get(int c)//get char in string
{
    return words[c];
}

MyString MyString::toUpper() {//convert all chars in string to upper case
    for (int i = 0; i < length(); ++i) {
        if(words[i]>97&&words[i]<122)//if char is within lowercase ASCII range
        {
            words[i]=words[i]-32;//shift ASCII value down to uppercase value
        }
    }
    MyString newStr(toString());
    return newStr;
}

MyString MyString::toLower() {//convert all chars in string to lower case
    for (int i = 0; i < length(); ++i) {
        if(words[i]>65&&words[i]<90)//if char is within uppercase ASCII range
        {
            words[i]=words[i]+32;//shift ASCII value up to lowercase value
        }
    }
    MyString newStr(toString());
    return newStr;
}

MyString MyString::substring(int sub) {//get substring of string
    int newLength=length()-sub;//length of sub
    char *temp =new char[newLength];//temporary array of size substring
    for (int i = sub; i < length(); ++i) {//transfer chars from sub position to length into temp
        temp[i-sub]=words[i];
    }
    delete words;//reset pointer
    words=new char [newLength];//new array of substring length
    for (int i = 0; i < newLength; ++i) {//transfer temp values to current string
        words[i]=temp[i];
    }
    curr_length=newLength;
    MyString newStr(toString());
    return newStr;
}

MyString MyString::substring(int l, int u) {//substring with range
    int newLength=u-l;//length defined by displacement between upper and lower bounds
    char *temp =new char[newLength];//method is basically the same as previous substring method
    for (int i = l; i < u; ++i) {
        temp[i-l]=words[i];
    }
    delete words;
    words=new char [newLength];
    for (int i = 0; i < newLength; ++i) {
        words[i]=temp[i];
    }
    curr_length=newLength;
    MyString newStr(toString());
    return newStr;
}

int MyString::indexOf(MyString& s) {//return the first occurence of string within current string
    for (int i = 0; i < length(); ++i) {//start from bottom, check every char
        if(s.get(0)==words[i]&&(i+s.length()<length()))//if char == first char of string
        {
            int matches=0;//count matches
            for (int j = 0; j < s.length(); ++j) {
                if(s.get(j)==words[i+j]){matches++;}//increment matches of char when we check along string length
            }
            if(matches==s.length()){return i;}//if correct number of char matches, assume its searched and return index
        }
    }
    return -1;//return -1 assuming insufficient matches
}

int MyString::lastIndexOf(MyString& s) {//basically indexOf but count backwards
    for (int i = length(); i > 0; --i) {
        if(s.get(0)==words[i]&&(i+s.length()<length())&&(i-s.length()>0))//add extra condition to make sure we dont go below index 0
        {
            int matches=0;
            for (int j = 0; j < s.length(); ++j) {
                if(s.get(j)==words[i+j]){matches++;}
            }
            if(matches==s.length()){return i;}
        }
    }
    return -1;
}
