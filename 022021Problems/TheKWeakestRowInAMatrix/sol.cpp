class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         for each row count the number of 1s using binary search
//         store the row indexes in a heap
        int rowSize = mat.size();
        int colSize = mat[0].size();
        
        vector<int> dict(rowSize);
        for (int i = 0; i < rowSize;i++) {
            dict[i] = countOnes(mat[i],colSize);
        }
        
        
        
        
        
        // return 
        
        priority_queue<int> pq;
        int cur;
        for (int i = 0; i < rowSize; i++) {
            cur = dict[i]*101 +i;
            if (pq.size() < k){
                pq.push(cur);
            } else if (pq.top() > cur){
                pq.pop();
                pq.push(cur);
            }
        }
        
        deque<int> dq;
        int curdq;
        while (pq.size()) {
            curdq = pq.top();
            pq.pop();
            dq.push_front(curdq%101);
        }
        
        
        
        
        return vector<int> (dq.begin(),dq.end());
    }
    int countOnes(vector<int> &row, int colSize) {
        int i = 0;
        int j = colSize-1;
        int m;
        while (i < j) {
            m = (j-i)/2 + i;
            if (row[m] == 1) {
                i = m+1;
            } else {
                j = m;
            }
        }
        if (j == colSize-1) {
            if (row[j] == 1) {
                return j+1;
            } else {
                return j;
            }
        } 
        return j;
    }
};
