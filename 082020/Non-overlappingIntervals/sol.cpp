#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

// struct by_index {
//     bool operator()(const vector<int> & a, const vector<int> & b) {
//         return a[0] < b[0];
//     }
// };

static bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // we can find the max number of non overlapping intervals and then subtract it from total number
    // for (int i=0; (unsigned)i < intervals.size(); ++i) {
    //     cout << intervals[i][0] << " " << intervals[i][1] << endl; 
    // }
    // max number of intervals is simply a greedy algorithm,
    // if we can ensure that for each pair of intervals, they are non overlapping, then all of them are overlapping.
    // simply sort, and compare the previous term.
    int n = intervals.size();
    if (!n) return 0;
    int count = 1;
    
    std::sort(intervals.begin(),intervals.end(),cmp);
    int end = intervals[0][1];
    for (int i=1; i < n; ++i) {
        // if the start is greater than the end, then not overlapping
        if (intervals[i][0] >= end) {
            count++;
            end = intervals[i][1];
        }
        // cout << count << " " << end << endl;
        // cout << intervals[i][0] << " " << intervals[i][1] << endl; 
    }
    // for (int i=0; i < n; ++i) {
    //     cout << intervals[i][0] << " " << intervals[i][1] << endl; 
    // }
    return n-count;
}

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
    int i = 0;
    while (getline(infile,line,']')) {
        stringstream rowstream(line);
        string row;
        while (getline(rowstream,row,'[')) {
            stringstream tuplestream(row);
            string element;
            if (row.length() > 1) {
                vector<int> tmp;
                v.push_back(tmp);
                while (getline(tuplestream, element, ',')) {
                    int num;
                    stringstream es(element);
                    es >> num;
                    v[i].push_back(num);
                }
                i++;
            }
            
        }
        // cout << line << endl;
    }
    infile.close();
    // cout << "input" << endl;
    // cout << v.size() << endl;
    // for (int i = 0; (unsigned) i < v.size(); ++i) {
    //     cout << v[i][0] << " " << v[i][1] << endl;
    // }

    int res = eraseOverlapIntervals(v);
    
    cout << "output" << endl;
    cout << res << endl;
    string s;
    getline(cin, s);
    return 0;

}