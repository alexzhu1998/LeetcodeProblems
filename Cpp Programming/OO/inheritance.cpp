#include <iostream>
#include <string>

using namespace std;


// constructors are resolved from deepest first
// destructors are resolved from the shallowest first
class MyBase {
    int _i;
public:
    MyBase (int i) : _i(i) {}
    void p() { cout << _i; }
};

class MyDerived : public MyBase {
    float _f;
public:
    MyDerived(float f, int i) 
        : _f(f), MyBase(i)
    {

    }
};

int main() {
    MyDerived d(1.0f, 2);
    d.p();
    string y;
    return 0;
}


// class Base {
// public:
//     int i;
//     void print() {}
// };
// // need public here 
// class S1 : public Base {
// public:
//     S1() {
//         i = 1;
//         print();
//     }
// };
// // need public here 
// class S2 : public S1 {
// public:
//     S2() {
//         i =3;
//         print();
//     }
// };

// class S2 : S1 {
// public:
//     S2
// };


// int main () {
//     return 0;    
// }