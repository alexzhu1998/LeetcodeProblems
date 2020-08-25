#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main () {
    int N = 4;
    // cin >> N;
    int arr[N] = {8,2,1,0};
    // int i = 0;
    // while (N--) {
    //     cin >> arr[i];
    //     i++;
    // }

    for (int j = 0; j < N; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;
    vector<int> diffV;
    // diffV.push_back(0);
    for (int i = 1; i < N; i++) {
        diffV.push_back(arr[i] - arr[i-1]);
    }
    int netNeg = INT8_MAX;
    int sum = diffV[0];
    for (int i = 1; (unsigned)i < diffV.size(); i++) {
        sum = min(sum+diffV[i],diffV[i]);
        if (netNeg > sum) netNeg = sum;
        cout << sum << " ";
        // netNeg = sum ? netNeg > sum;
    }
    cout << netNeg <<endl;

    
    string x;
    getline(cin,x);

}