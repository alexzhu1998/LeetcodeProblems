#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss;

        ss << S;
        string word;
        string res;
        int i = 1;
        while (ss >> word) {
            
            char front = tolower(word[0]);
            string a(i,'a');
            if (front == 'a'|| front == 'e' || front == 'i' || front == 'o' || front == 'u') {
                res += word + "ma" + a + " ";
            } else {
                res += word.substr(1,word.length()) + word[0] + "ma" + a + " ";
            }
            // cout << word << endl;
            i++;
        }
        res = res.substr(0,res.length()-1);
        return res;
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
    
    getline(infile,line);
    line = line.substr(1,line.length()-2);

    Solution answer;
    string res = answer.toGoatLatin(line);

    cout << '\"' << res << '\"' << endl;

}