/*MyString - CST 201 PROJECT 2 - 1/12/22 - by Nathan Dilla :)*/
#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

int main() {
    MyString hello("Hello");
    cout<<hello.toString()<<endl;
    MyString world("world");
    cout<<world.toString()<<endl;
    MyString helloWorld;
    helloWorld = hello.concat(world);
    cout<<helloWorld.toString()<<endl;
    cout<<"Hello == Hello?"<<hello.equals(hello)<<endl;
    cout<<"Hello == world?"<<hello.equals(world)<<endl;
    cout<<"compare Hello & Hello?"<<hello.compareTo(hello)<<endl;
    MyString apple("Apple");
    cout<<"compare Hello & Apple?"<<hello.compareTo(apple)<<endl;
    cout<<"compare Hello & world?"<<hello.compareTo(world)<<endl;
    MyString hello2(hello);
    cout<<"world to upper: "<<world.toUpper().toString()<<endl;
    MyString hello3("HeLLo");
    cout<<"HeLLo to upper: "<<hello3.toUpper().toString()<<endl;
    MyString hello4("HeLLo");
    cout<<"HeLLo to lower: "<<hello3.toLower().toString()<<endl;
    cout<<"substring of Helloworld at 4: "<<helloWorld.substring(4).toString()<<endl;
    cout<<"substring of HeLLo at 2 and 4: "<<hello4.substring(2,4).toString()<<endl;

    MyString substr("bruh");
    MyString substr2("brother");
    MyString somestr("The quick bruh jumped over the bruh lazy bruh.");
    cout<<somestr.toString()<<": string to be searched"<<endl;
    int findSubstr = somestr.indexOf(substr);
    cout<<"search for bruh: "<<findSubstr<<endl;
    findSubstr = somestr.indexOf(substr2);
    cout<<"search for brother: "<<findSubstr<<endl;
    findSubstr = somestr.lastIndexOf(substr);
    cout<<"search last for bruh: "<<findSubstr<<endl;
    findSubstr = somestr.lastIndexOf(substr2);
    cout<<"search last for brother: "<<findSubstr<<endl;
    return 0;
}

