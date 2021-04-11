#include <iostream>
#include <string>


using namespace std;

int return_one () {return 1;}

int* AVOID_THIS() {
    int a = 2; 
    return &a;
}// a destroyed!! garbage value

int* AVOID_THIS_TOO () {
    int *b = new int[5];
    return b; //Bad!! memory leak! need to make unique pointer
}

int& AVOID_THIS_ALSO () {
    int c = 4;
    return c;
}

int main () {
    int *x, *y, z;
    x = AVOID_THIS();
    cout << *x << endl;
    y = AVOID_THIS_TOO();
    cout << *y << endl;
    z = AVOID_THIS_ALSO();
    cout << z << endl;
    return 0;
}