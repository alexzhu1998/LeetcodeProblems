class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
//         for each element in the new array B, find the smallest element in A that is larger than B[i]
//         binary search through A
        
//         need to account for cases like B = [4,3,5,2], A = [10,3,4,5] if 10 gets put into 4 first, then its not optimal
//         
        multiset<int> s(begin(A), end(A));
        for (auto i = 0; i < B.size(); ++i) {
            auto p =  s.upper_bound(B[i]);
            if(p == s.end()) p =s.begin();
            A[i] = *p;
            s.erase(p);
        }
        return A;
    }
};
