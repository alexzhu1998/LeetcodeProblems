class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1) return 0;
        if (arr.back() == arr[0]) return 1;
        const int n = arr.size();
        // vector<int> dp(arr.size(),INT_MAX);
        unordered_map<int,vector<int>> m;
        for (int i = 0; i < n;i++) m[arr[i]].push_back(i);
        queue<int> q{{0}};
        vector<int> visited(n,0);
        visited[0] = 1;
        for (int step = 0; !q.empty(); step++) {
            for(int i = q.size(); i>0;i--){
                int cur = q.front(); q.pop();
                if (cur == n-1) return step;
                for (int k: {cur+1,cur-1}) {
                    if (k< n && k >= 0 && !visited[k]) q.push(k), visited[k]=1;
                }
                auto& nexts = m[arr[cur]];
                for (int k: nexts) {
                    if (!visited[k]) q.push(k),visited[k] =1;
                }
                nexts.clear();
            }
        }
        
        
        // for (auto itr = m.begin(); itr != m.end(); itr++) 
        // { 
        //     // itr works as a pointer to pair<string, double> 
        //     // type itr->first stores the key part  and 
        //     // itr->second stroes the value part 
        //     cout << itr->first << "  " ;
        //     for (auto i : itr->second) {
        //         cout<< i << " ";
        //     }
        //     cout<<endl;
        // } 
        
        
        return arr.size()-1;
    }
};
