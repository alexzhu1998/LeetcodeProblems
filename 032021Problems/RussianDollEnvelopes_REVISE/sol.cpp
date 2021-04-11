//Longest Increasing Subsequence after a clever sort
bool sortfoo(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) return (a[1] > b[1]);
    return (a[0] < b[0]);
} 

// bool sortfoo2(vector<int> &a, vector<int> &b) {
    // if (a[1] != b[1]) return (a[1]< b[1]);
    // return (a[0] < b[0]);
// } 
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort the array
//         then longest increasing sub
        sort(envelopes.begin(),envelopes.end(),sortfoo);
        int res = 0;
        int n = envelopes.size();
        vector<int> d(n,1);
        for (int i =0; i < n;i++) {
            for (int j = 0; j < i;j++) {
                if (envelopes[j][1] < envelopes[i][1]) {
                    d[i] = max(d[i], d[j]+1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            res= max(res,d[i]);
        }
        
        return res;
    }
};

// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//       sort(envelopes.begin(), envelopes.end(), 
//            [](const vector<int> &A, const vector<int> &B) {
//              if (A[0] == B[0]) return A[1] > B[1];
//              return A[0] < B[0];
//            }
//           );
//       vector<int> tab;
//       for (auto &e: envelopes) {
//         auto it = lower_bound(tab.begin(), tab.end(), e[1]);
//         if (it == tab.end()) {
//           tab.push_back(e[1]);
//         } else {
//           *it = e[1];
//         }
//       }
//       return tab.size();
//     }
// };
