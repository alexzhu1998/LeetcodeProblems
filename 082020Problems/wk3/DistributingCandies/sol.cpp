#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
    vector<int> res(num_people,0);
    
    // for (int item:res) {
    //     cout<< item <<endl;
    // }
    int cd = 1;
    int i = 0;
    while (candies >= 0) {
        if (candies>=cd) {
            res[i%num_people] += cd;
            
        } else {
            res[i%num_people] += candies;
        }
        // cout << candies << endl;
        i++;
        candies -= cd;
        cd++;
    }
    return res;
}

int main() {
    std:: ios_base:: sync_with_stdio(false);

    ifstream infile("input.txt");
    int c,num_ppl;
    infile >> c;
    infile >> num_ppl;
    
    vector<int> res;
    res = distributeCandies(c,num_ppl);
    cout << '[';
    for (int item: res) {
        cout << item << ',';
    }
    cout << '\b' << ']' << endl;


    string s;
    getline(cin, s);
    return 0;
}