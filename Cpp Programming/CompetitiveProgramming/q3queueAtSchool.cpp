// #include <iostream>
// #include <string>
#include <bits/stdc++.h>

using namespace std;

int numPpl,shifts;
string arrangement;

string shifting(string &input) {
    
    while(shifts--) {
        for (int i = 0; i < numPpl-1;) {
            if (input[i] == 'B' && input[i+1] == 'G') {
                char tmp = input[i+1];
                input[i+1] = input[i];
                input[i] = tmp;
                i+=2;
            } else {
                i++;
            }
        }
    }
    
    
    return input;
}

int main () {
    ios::sync_with_stdio(0);
    
    cin >> numPpl >> shifts;
    cin >> arrangement;
    
    

    string result = shifting(arrangement);
    // cout << "Output" << endl;
    cout << result << endl;
    // getline(cin,arrangement);
    // cout << numPpl << endl;
    // cout << shifts << endl;
    // cout << arrangement << endl;

    return 0;

}