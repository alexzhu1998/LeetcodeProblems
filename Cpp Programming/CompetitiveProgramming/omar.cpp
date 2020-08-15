#include <iostream>
#include <string>

using namespace std;
int main (int argc, char* argv[]) {
    int count;
    cin >> count;
    const int length = count;
    string inputArr[length];
    for (int i = 0; i < length; i++) {
        cin >> inputArr[i];
    }

    return 0;
}