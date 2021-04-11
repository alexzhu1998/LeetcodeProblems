#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        // int length = N;
        vector<int> res;
        // while (length--) {
            
        // }
        if (N == 1) res.push_back(0);
        for (int i = 1; i < 10; i++) {
            dfs(N-1,K,i,res);
        }
        // sort(res.begin(),res.end());
        // for (int i = 0; i < res.size(); i++) {

        // }
        return res;
    }
private:
    void dfs(int N, int K, int cur, vector<int> &ans) {
        if (N == 0) {
            ans.push_back(cur);
            return;
        }
        int l = cur%10;
        if (l+K < 10) {
            dfs(N-1,K,cur*10+l+K,ans);
        }
        if (l-K >= 0 && K!=0) {
            dfs(N-1,K,cur*10+l-K,ans);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    ifstream infile("input.txt");
    string line;
    if (!infile) {
        cerr << "error: can't open file" << endl;
        abort();
    }
    vector<int> v;
    
    int N;
    int K;
    infile >> N;
    infile >> K;

    Solution answer;
    v = answer.numsSameConsecDiff(N,K);
    if (v.size() > 0) {
        cout << '[';
        for (int i = 0; (unsigned) i < v.size()-1; ++i) {
            cout << v[i] << ',';
        }
        cout << v[v.size()-1] << ']' << endl;
    } else {
        cout << '[' << ']' << endl;
    }
    
    // cout << N << " " << K << endl;
}