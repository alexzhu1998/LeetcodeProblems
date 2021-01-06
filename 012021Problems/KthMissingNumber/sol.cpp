class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 1;
        for (int i = 0; i < arr.size();i++) {
            j = arr[i]-i-1;
            if (j>=k) {
                return arr[i] - (j-k)-1;
            } 
        }
        return arr.back()+k-j;
    }
};
// 2 3 4 8 9
// 6
// 1 1 1 4 4

// 3
// 1

// 2 3 8 9 10
// 1 1 5 5 5
// 3

// class Solution {
// public:
//   __inline int findKthPositive(vector<int>& A, int k) 
//   {
//         std::ios::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);

//         int l = 0, r = A.size(), m;
//         while (l < r) 
//         {
//             m = (l + r) >> 1;
//             if (A[m] - 1 - m < k)
//                 l = m + 1;
//             else
//                 r = m;
//         }
//         return l + k;
//     }
// };
