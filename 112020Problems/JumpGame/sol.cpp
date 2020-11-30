class Solution {
public:
    //         dfs to value arr[i] == 0
    bool canReach(vector<int>& arr, int i) {
        
        queue<int> q;
        set<int> s;
        q.push(i);
        while (q.size()) {
            int last = q.front();
            q.pop();
            std:: cout << last << std::endl;
            if (last >= arr.size() || last < 0 || s.find(last) != s.end()) continue;
            if (arr[last] == 0) return 1;
            s.insert(last);
            q.push(last+arr[last]);
            q.push(last-arr[last]);
            
        }
        return 0;
    }
//     bool bfs(vector<int> & arr, int i, set<int>& s) {
//         if (i >= arr.size() || i < 0) return 0;
//         if (i-arr[i] < arr.size() && i -arr[i] >= 0) {
//             s.add(i-arr[i]);
//         } 
        
//         if (!bfs(arr,i-arr[i],s)) {
//             s.erase(i-arr[i]);
//         } else if (!bfs(arr,i+arr[i],s)) {
//             s.erase(i+arr[i]);
//         }
        
            
//     }
};

// class Solution {
// public:
//     bool canReach(vector<int>& arr, int start) {
//         if (start < 0 || start >= arr.size()) return false;
//         if (arr[start] == 0) return true;
//         if (arr[start] < 0) return false;
//         arr[start] = -arr[start];
//         if (canReach(arr, start + arr[start]) || canReach(arr, start - arr[start])) return true;
//         return false;
//     }
// };