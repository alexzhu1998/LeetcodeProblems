class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
//         for each pair of elements in the array, apply a swap
//         recursively permute smaller vectors
        vector<vector<int>> res;
//         if (nums.size() == 1) {
//             res.push_back(nums);
//             return res;
//         }
// //          
//         return res;
        sort(nums.begin(),nums.end());
        return permute(nums);
    }
    
    vector<vector<int>> permute(vector<int> nums) {
        vector<vector<int>> res;
//         base case
        if (nums.size() == 1) {
            res.push_back(nums);
            return res;
        }
        
        
        set<int> s;
        for (int i =0; i < nums.size(); i++) {
            vector<int> temp = nums;
            
//             remove duplicate elements in the list
            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            } else {
                continue;
            }
//             remove the ith element
            temp.erase(temp.begin()+i);
            
            
//             insert the ith element to each of the permuted value of the remaining list
            vector<vector<int>> tempList = permute(temp);
            for (int k = 0; k < tempList.size() ; k++) {
                tempList[k].insert(tempList[k].begin(),nums[i]);
                res.push_back(tempList[k]);
                // for (int j =0 ; j < tempList[k].size();j++) {
                //     std::cout << tempList[k][j] << " ";
                // }
                // std::cout<< std::endl;
            }
            
            
            
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> result;
//         findPU(nums, 0, result);
//         return result;
//     }
    
    
//     void findPU(vector<int>& nums, int start, vector<vector<int>>& result){
//         if(start == nums.size()){
//             result.push_back(nums);
//             return;
//         }    
        
//         int len = nums.size();
//         for(int i=start; i<len; i++){
//             int j = i - 1;
//             while (j >= start && nums[j] != nums[i]) --j;
//             if (j != start - 1) continue;
            
//             swap(nums[start], nums[i]);
//             findPU(nums, start+1, result);
//             swap(nums[start], nums[i]);
//         }
        
//         return;
//     }
// };