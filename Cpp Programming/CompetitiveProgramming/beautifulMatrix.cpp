#include <iostream>

using namespace std;

const int size = 5;
int arr[size]{};

int main() {
    int num;
    int res = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> num;
            if (num == 1) {
                if (i > size/2) {
                    res += i -size/2;
                } else {
                    res += size/2 - i;
                }
                if (j > size/2) {
                    res += j -size/2;
                } else {
                    res += size/2 - j;
                }
                
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}