#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

// class Solution {
// public:
//     Solution(vector<vector<int>>& rects) {
        
//     }
    
//     vector<int> pick() {
        
//     }
// };

int main () {
    std::ios_base::sync_with_stdio(false);

    ifstream infile("input.txt");
    string line;
    if (!infile) {
        cerr << "error: can't open file" << endl;
        abort();
    }
    // char ch;
    vector<string> v;
    getline(infile,line);
    line = line.substr(1,line.length()-2);
    stringstream ss(line);
    while (ss.good()) {
        string substr;
        getline(ss,substr,',');
        substr = substr.substr(1,substr.length()-2);
        v.push_back(substr);
    }
    getline(infile,line);
    line = line.substr(1,line.length()-2);
    stringstream sss(line);
    while (sss.good()) {
        string substr;
        getline(sss,substr,']');
        if (substr.find_first_not_of(' ') == string::npos) continue;
        // substr = 
        cout << substr << endl;
    }



    infile.close();
    // cout << "input" << endl;
    // cout << v.size() << endl;
    // for (int i = 0; (unsigned) i < v.size(); ++i) {
    //     cout << v[i] << endl;
    // }

    
}