class Solution {
public:
    int numDecodings(string s) {
        vector<int> count(s.size(),0);
        string s1 = s.substr(0,1);
        
        if (s1 == "0") {
            return 0;
        } else {
            count[0] = 1;
            if (s.size() == 1) return count.back();
        }
        string s2 = s.substr(0,2);
        s1 = s.substr(1,1);
        if (s2 <= "26" && s2 >= "10") {
            if (s1 == "0") {
                count[1] = count[0];
            } else {
                count[1] = count[0] + 1;    
            }
            
        } else {
            if (s1 == "0") {
                return 0;
            } else {
                count[1] = count[0];
            }
            
        }
        // for (int i = 0; i < count.size();i++) cout<<count[i] <<" ";
        for (int i = 2; i < s.size();i++) {
            s1 = s.substr(i,1);
            s2 = s.substr(i-1,2);
            if (s2 <= "26" && s2 >= "10") {
                if (s1 == "0") {
                    count[i] = count[i-2];
                } else {
                    count[i] = count[i-1] + count[i-2];
                }
            } else {
                if (s1 == "0") {
                    return 0;
                }else {
                    count[i] = count[i-1];
                }
                
            }
        }
        return count.back();
    }
};

// class Solution {
// public:
//     int numDecodings(string s) {
//         // unordered_map<string,int> umap;
//         // for (int i = 0; i <26; i++) {
//         //     umap[string(1,'A'+i)] = i+1;
//         // }
//         // for (auto itr = umap.begin(); itr != umap.end(); itr++) { 
//         //     // itr works as a pointer to pair<string, double> 
//         //     // type itr->first stores the key part  and 
//         //     // itr->second stroes the value part 
//         //     cout << itr->first << "  " << itr->second << endl; 
//         //  } 
//         int count = 0;
//         if (s.size() == 0) {
//             return 0;
//         } else if (s.size() == 1) {
//             if (s == "0") {
//                 return 0;
//             } else {
//                 return 1;
//             }
//         }  
        
//         // cout<< s.substr(0,2) <<endl;
//         cout<< s.size() <<endl;
//         if (s.substr(0,1) <= "9" && s.substr(0,1) >= "1") {
//             count += numDecodings(s.substr(1,s.size()-1));
//         }
//         if (s.substr(0,2) <= "26" && s.substr(0,2) >= "10") {
//             if (s.size() == 2) {
//                 count++;
//             } else {
//                 count += numDecodings(s.substr(2,s.size()-2));
//             }
            
//         }
        
// //         partition the string into list of non repeated strings (use recursion)
        
//         return count;
        
//     }
// };
