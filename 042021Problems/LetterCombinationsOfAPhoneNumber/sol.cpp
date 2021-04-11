class Solution {
public:
    
    vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;
        for (int k = 0; k < digits.length();k++) {
            vector<string> newS;
            for (int i = 0; i < map[digits[k]-'0'].length(); i++) {
                if (res.empty()) {
                    newS.push_back(string(1,map[digits[k]-'0'][i]));
                } else {
                    for (int j = 0; j < res.size();j++) {
                        // cout << i << " " << j << endl;
                        newS.push_back(res[j]+map[digits[k]-'0'][i]);
                    }
                }
            }
            res.swap(newS);
        }
        return res;
    }
    
//     void dfs(vector<string>& s, string& digits, int d) {
//         if (d == digits.length()) return;
//         vector<string> newS;
//         for (int i = 0; i < vec[digits[d]-'0'].size();i++) {
//             if (s.empty()) {
//                 newS.push_back(string(1,vec[digits[d]-'0'][i]));
//             } else {
//                 for (int j = 0; j < s.size();j++) {
//                     // cout << i << " " << j << endl;
//                     newS.push_back(s[j]+vec[digits[d]-'0'][i]);
//                 }
//             }
//         }
//         s = newS;
//         dfs(s,digits,d+1);
        
        
//     }
};
