#include <iostream>

using namespace std;

double square(double x);
int square(int x);

int main() {
    double x;
    cout << "Enter a number ";
    cin >> x;
    cout << square(x) << endl;
    int y;
    cout << "Enter an integer ";
    cin >> y;
    cout << square(y) << endl;
    return 0;
}

double square(double x) {
    cout << "From double version" << endl;
    return x*x;
}

int square(int x) {
    cout << "From double version" << endl;
    return x*x;
}