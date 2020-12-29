class Solution {
public:
    int reachNumber(int target) {
//         mathematical solution
        target = abs(target);
        
        int sum = 0;
        int i;
        for (i = 1;;i++) {
            if (sum < target || (sum-target)%2 == 1) {
                sum += i;
            } else {
                break;
            }
        }
        
        // cout << sum << endl;
        return i-1;
        
        
    }
};
// bfs exceed time limit
// int reachNumber(int target) {
//         int cur = 0;
//         queue<int> level;
//         level.push(cur);
//         for(int step =1;;step++) {
//             int n = level.size();
//             unordered_set<int> visited;
//             for (int i = 0; i < n; i++) {
//                 cur = level.front();level.pop();
//                 if (cur == target) return step-1;
//                 if (visited.find(cur) != visited.end()) continue;
//                 if (visited.find(cur+step) == visited.end()) level.push(cur+step);
                
//                 if (visited.find(cur-step) == visited.end()) level.push(cur-step);
//                 visited.insert(cur);
                
//             }
//         }        
        
//         return 0;
//     }
