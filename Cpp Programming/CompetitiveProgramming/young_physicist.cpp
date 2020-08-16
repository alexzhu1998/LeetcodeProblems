#include <iostream>
#include <string>

using namespace std;

const int dim = 3;
int n, a[100][dim], res[dim]{};

int main () {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < dim; ++j) {
            cin >> a[i][j];
            res[j] += a[i][j];
        }
    }

    for (int i = 0; i < dim; i++) {
        if (res[i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}