#include <iostream>

using namespace std;

class MyBase {
public:
    virtual void print() {
        cout << "inside Base\n";
    }
    // this line below forces other derived class to print
    // virtual void print() = 0;
};

class MyDerived : public MyBase {
public:
// if we comment out this function,it will just run the base class
// it is recommended to add virtual to each subclass
    void print() {
        cout << "inside Derived\n";
    }
};

int main ()
{
    MyDerived d;
    d.print();

    MyBase& b = d;
    b.print();

    MyBase b2;
    b2.print();

    return 0;
}