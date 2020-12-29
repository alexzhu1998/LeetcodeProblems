class Solution {
public:
    int nextGreaterElement(int n) {
//         need to account for 132 -> 213 not 312
//         need to 154321 -> 211345
//         254321-> 312245
        vector<int> vec;
        while (n > 0) {
            vec.push_back(n%10);
            n = n/10;
        }
        int i;
//         stop at the non decreasing number, sort everything before
        for (i = 1; i < vec.size();i++) {
            if (vec[i] < vec[i-1]) {
                break;
            }
        }
        if (i == vec.size()) return -1;
        int j;
        for (j = 0; j < i; j++) {
            if (vec[j] > vec[i]) {
                break;
            }
        }
        int temp = vec[j];
        vec.erase(vec.begin() + j);
        
        vec.insert(vec.begin()+i,temp);
        sort(vec.begin(),vec.begin()+i,greater<int>());
        
        // for (int k = 0; k < vec.size();k++) {
        //     cout<<vec[k] << " ";
        // }
        long res = vec[vec.size()-1];
        for (int k =vec.size()-2; k >= 0;k--){
            res *= 10;
            if (res > INT_MAX) return -1;
            res += vec[k];
        }
        
        return res;
        
        
    }
};

// class Solution {
// public:
//     int nextGreaterElement(int n) {
//         string num = to_string(n);
        
//         if (num.size() == 1) return -1;
        
//         int i = num.size() - 2;
    
//         while (i >= 0 && num[i] >= num[i + 1]) {
//             i--;
//         }
        
//         if (i < 0) return -1;
        
//         int j = i + 1;
//         while (j < num.size() && num[j] > num[i]) {
//             j++;
//         }
//         j = j - 1;
        
//         swap(num[j], num[i]);
        
//         int l = i + 1;
//         int r = num.size() - 1;
        
//         while (l < r) {
//             swap(num[l], num[r]);
//             l++;
//             r--;
//         }
        
//         long long val = atol(num.c_str());
        
//         if (val > INT_MAX) return -1;
//         else return val;
//     }
// };
