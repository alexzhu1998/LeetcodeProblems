class Solution {
public:
    int longestSubstring(string s, int k) {
       int max_len = 0;
       for (int first = 0; first+k <= s.size();) {
           int count[26] = {0};
           int mask = 0;
           int max_last = first;
           for (int last = first; last < s.size(); ++last) {
               int i = s[last] - 'a';
               count[i]++;
               if (count[i]<k) mask |= (1 << i);
               else   mask &= (~(1 << i));

               if (mask == 0) {
                   max_len = max(max_len, last-first+1);
                   max_last = last;
               }
           }
           first = max_last + 1;
       }
       return max_len;
    }
};

// class Solution {
// public:
//     int longestSubstring(string s, int &k) {
//         int m[26] = {0}, idx[26] = {0} ;
//         unordered_set<char> less;
//         int len = s.length();
//         int i =0 , br;

//         if (len < k) {
//             return 0;
//         }
//         for (i = 0; i < s.length(); i++) {
//             m[s[i]-'a']++;
//             idx[s[i] - 'a'] = i;
//         }
//         for ( i =0; i < 26; i++) {
//             if (m[i] != 0 && m[i] < k) {
//                 br = idx[i];
//                 break;
//             }
//         }
//         if (i == 26) {
//             return s.length();
//         }
        

//         int r1 = longestSubstring(s.substr(0,br), k);
//         int r2 = longestSubstring(s.substr(br+1, len-br+1), k);
//         return r1>r2? r1:r2;
//         return 0;
//     }
// };
