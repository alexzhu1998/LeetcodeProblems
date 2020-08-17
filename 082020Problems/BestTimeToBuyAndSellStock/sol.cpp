#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// int maxProfit(vector<int> &prices) {
//     int firstBuy = INT8_MAX, secondBuy = INT8_MAX, firstProf = INT8_MIN, secondProf = INT8_MIN;
//     for (int cur: prices) {
//         firstBuy = min(firstBuy,cur);
//         firstProf = max(firstProf, cur - firstBuy);
//         // buy again the second time since the price dropped below our profit value
//         secondBuy = min(secondBuy,cur - firstProf);
//         secondProf = max(secondProf, cur - secondBuy);
//         // cout << cur << " "<< firstBuy << " " << firstProf << " " << secondBuy << " " << secondProf << endl;
//     }
    
//     return secondProf;
// }

int maxProfit(vector<int> &prices) {
    const int n = prices.size();
    if (n == 0) return 0;
    int minLeft = prices[0];
    vector<int> left (n,0);
    vector<int> right (n,0);
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i-1],prices[i]-minLeft);
        minLeft = min(minLeft, prices[i]);
    }
    int maxRight = prices[n-1];
    for (int i = n-2; i >= 0; i--) {
        right[i] = max(right[i+1], maxRight - prices[i]);
        maxRight = max(maxRight, prices[i]);
    }

    int maxProfit = 0;
    for (int i =0; i < n; i++) {
        maxProfit = max(maxProfit, left[i] + right[i]);
    }


    return maxProfit;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    ifstream infile("input.txt");
    string line;
    if (!infile) {
        cerr << "error: can't open file" << endl;
        abort();
    }
    vector <int> v;
    while (getline(infile,line)) {
        line = line.substr(1,line.size()-2);
        // cout << line << endl;
        stringstream elestream(line);
        string element;
        while (getline(elestream,element, ',')) {
            if (element.length() > 0) {
                int num;
                stringstream es(element);
                es >> num;
                v.push_back(num);
            }
        }
    }

    // for (int i =0; (unsigned) i< v.size(); i++) {
    //     cout << v[i] << endl;
    // }
    int res = maxProfit(v);
    cout << "Output" << endl;
    cout << res << endl;
    return 0;
}