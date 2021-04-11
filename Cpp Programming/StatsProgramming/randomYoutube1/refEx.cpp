#include <iostream>

using namespace std;

void f(int &j){
    j++;
    cout << &j << endl;
}

int main() {
    int i = 2;
    cout << &i << endl;
    f(i);
    cout<< i << endl;

    int &j = i;
    int k = j;
    cout << i << " " << j << " " << k << endl;
    cout << &i << " " << &j << " " << &k << endl;

    k++;
    j=k;
    // i will = 4
    cout << i << " " << j << " "<< k << endl;
    cout << &i << " " << &j << " " << &k << endl;
    return 0;
}
// two ways to reference stuff
    // int* j = &i;
    // int* k = j;
    // cout << i << " " << *j << " " << *k << endl;
    // cout << &i << " " << &j << " " << &k << endl;

    // k[0]++;
    // j=k;
    // // i will = 4?
    // cout << i << " " << *j << " "<< *k << endl;
    // cout << &i << " " << &j << " " << &k << endl;
    // return 0;