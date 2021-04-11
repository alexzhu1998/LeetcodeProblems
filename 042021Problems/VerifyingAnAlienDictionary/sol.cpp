class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mp[26];
        for (int i=0; i<26; ++i)
            mp[order[i] - 'a'] = i;
        
        for (auto &w : words) {
            for (char &c : w) {
                c = mp[c-'a'];
            }
        }
        
        return is_sorted(words.begin(), words.end());
    }
};

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;
        int c = 0;
        for (auto letter: order) {
            m[letter] = c;
            c++;
        }
        
        for (int i = 1; i < words.size();i++) {
            int sorted = 0;
            int k = 0;
            // cout << words[i] << " " << words[i-1] << endl;
            int len = min(words[i].length(),words[i-1].length());
            while (k < len) {
                if (m[words[i][k]] < m[words[i-1][k]]) {
                    return false;
                } else if (m[words[i][k]] > m[words[i-1][k]]) {
                    sorted = 1;
                    break;
                }
                k++;
            }
            if (sorted == 0 && (words[i].length() < words[i-1].length())) {
                return false;
            }
        }
        return true;
        
    }
};
