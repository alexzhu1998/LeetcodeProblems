#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        
    }
    
    vector<int> pick() {
        
    }
};

int main () {
    std::ios_base::sync_with_stdio(false);

    ifstream infile("input.txt");
    string line;
    if (!infile) {
        cerr << "error: can't open file" << endl;
        abort();
    }
    // char ch;
    vector<vector<int>> v;
    getline(infile,line);
    line = line.substr(1,line.length()-2);
    

    infile.close();
    // cout << "input" << endl;
    // cout << v.size() << endl;
    // for (int i = 0; (unsigned) i < v.size(); ++i) {
    //     cout << v[i][0] << " " << v[i][1] << endl;
    // }

    
}