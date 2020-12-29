class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int res = A.back() - A[0];
        int minv,maxv;
        for (int i = 0; i < A.size()-1; i++) {
            minv = min(A[0]+K,A[i+1]-K);
            maxv = max(A.back()-K,A[i]+K);
            res = min(res,maxv-minv);
        }
        
        
        return res;
    }
};
