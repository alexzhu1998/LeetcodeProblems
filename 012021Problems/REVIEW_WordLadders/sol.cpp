// class Solution {
// public:
//     bool OffByOne(string a, string b) {
//         int c = 0;
//         for (int i = 0; i < a.size() && c< 2; i++) {
//             if (a[i] != b[i]) {
//                 c++;
//             }
//         }
//         return c == 1;
//     }
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         queue<string> q;
//         q.push(beginWord);
//         int ans = 0;
//         unordered_map <string,vector<string>> mp; 
//         wordList.push_back(beginWord);
//         for (int i = 0; i < wordList.size();i++) {
//             for (int j = 0; j < wordList.size();j++) {
//                 if (i != j && OffByOne(wordList[i],wordList[j])) {
//                     mp[wordList[i]].push_back(wordList[j]);
//                 }
//             }
//         }
//         while (!q.empty()) {
//             ans++;
//             int cnt = q.size();
//             while (cnt-->0) {
//                 auto word =  q.front();
//                 q.pop();
//                 if (word == endWord) {
//                     return ans;
//                 }
//                 if (mp.find(word) != mp.end()) {
//                     for (auto w: mp[word]) {
//                         q.push(w);
//                     }
//                     mp.erase(word);
//                 }
//             }
            
//         }
//         return 0;
        
//     }
// };
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead -> begin(); it != phead -> end(); it++) {    
                string word = *it;
                for (int i = 0; i < word.size(); i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (ptail -> find(word) != ptail -> end()) {
                            return ladder;
                        }
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            ladder++;
            phead -> swap(temp);
        }
        return 0;
    }
};



// class Solution {
// public:
//     int ladderLength(string beg, string end, vector<string>& List) {
//         queue<string> q;
       
//         unordered_set<string> st(List.begin(),List.end());
        
//         //when end is not in list 
//          if(st.count(end) == 0) 
//              return 0;
//          q.push(beg);
    
//         int cnt = 0;
        
//         while(!q.empty()){
//             int p = q.size();
//             cnt++;
//             while(p--){
//                 string s = q.front();
//                 q.pop();
                
//                 for(int i=0;i<s.size();i++){
//                     string tmp = s;
//                     for(char j='a';j<='z';j++){
//                         tmp[i] = j;
//                         if(tmp == end) return ++cnt;
//                         if(st.count(tmp) == 0) 
//                             continue;
                        
//                         q.push(tmp);
//                        st.erase(tmp);
//                     }
//                 }
//             } 
//         }
//         return 0;
//     }
// };
