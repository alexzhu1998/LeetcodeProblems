#include <iostream>
#include <string>
using namespace std;

void increment_Array(double* array, int SIZE)
{
    for (int i = 0; i < SIZE; i++) {
        array[i]++;
    }
}

int main () {
    int x = 5;
    cout << x << endl;

    cout << x << endl;

    double super_array[] {1,2,3,4.5,77.7};
    increment_Array(super_array,5);

    for (int i = 0; i < 5; i++) {
        cout << super_array[i] << endl;
    }

    string s;
    getline(cin, s);
    return 0;
}

