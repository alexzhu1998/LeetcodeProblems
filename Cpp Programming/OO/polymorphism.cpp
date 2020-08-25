#include <iostream>
#include <string>
using namespace std;


class Base {
public:
    void Print() {
        cout << "inside Base" << endl;
    }
};

class Derived : public Base {
public:
    void Print() {
        cout << "inside Derived" << endl;
    }
};

int main () {
    Base b;
    Derived d;
    b.Print();
    d.Print();

    // adding class to itself, note it is able to find its base
    Base &br = d;
    Derived &dr = d;
    br.Print();
    dr.Print();
    
    // when a base class pointer calls each of their pointers, it is able to find 
    // its base class functions
    Base* bp = new Derived();
    Derived* dp = new Derived();
    bp->Print();
    dp->Print();

    auto*ap = new Derived();
    ap->Print();

    delete bp;
    delete dp;
    delete ap;
    return 0;
}