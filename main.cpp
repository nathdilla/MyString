/*MyString - CST 201 PROJECT 1 - 1/12/22 - by Nathan Dilla :)*/
#include <iostream>
#include <string>
#include "MyString.h"
using namespace std;

int main() {
    MyString test("Hello");
    cout<<test.toString()<<endl;
    MyString add("world");
    cout<<add.toString()<<endl;
    test.concat(add);
    return 0;
}

