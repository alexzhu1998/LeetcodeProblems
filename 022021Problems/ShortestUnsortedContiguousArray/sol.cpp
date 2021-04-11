// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
// //         initiate two pointers, from middle, build a range
// //         if the elements to the left is not less than the min, then add 1 to it
//         vector<int> a = nums;
//         // for (int i = 0; i < nums.size();i++) {
//         //     a.push_back(nums[i]);
//         // }
//         sort(nums.begin(),nums.end());
//         int i;
//         bool flag = 0;
//         for (i = 0; i < nums.size();i++) {
//             if (a[i] != nums[i]) {
//                 flag = 1;
//                 break;
//             }
//         }
//         int j; 
//         for (j = nums.size()-1; j >= 0;j--) {
//             if (a[j]!= nums[j]) {
//                 flag = 1;
//                 break;
//             }
//         }
        
//         if (flag) return j-i+1;
//         return 0;
//     }
// };

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int leftIndex = 0, rightIndex = nums.size()-1, N = nums.size();
        bool flag = false;
        for(int i =0; i<N-1; i++)
        {
            if(nums[i]>nums[i+1]) 
            {
                flag = true;
                leftIndex = i;
                break;
            }
        }
        if(!flag) return 0;
        
        for(int i =N-1; i>=0 && i>leftIndex; i--)
        {
            if(nums[i]<nums[i-1]) 
            {
                rightIndex = i;
                break;
            }
        }
        int minVal = INT_MAX, maxVal = INT_MIN;
        
        
        for(int i = leftIndex; i<=rightIndex; i++)
        {
            minVal = min(minVal,nums[i]);
            maxVal = max(maxVal,nums[i]);
        }
        
        int minIndex = leftIndex, maxIndex = rightIndex;
        for(int left = leftIndex; left>=0; left--)
        {
            if(nums[left] > minVal) minIndex=left; 
        }
        
        for(int right = rightIndex; right<N;right++)
        {
            if(nums[right]<maxVal) maxIndex = right;
        }
        
        /*
        i/p:    [2,6,4,8,10,9,15] leftIndex = 1, rightINdex = 5
                
        */
        
        return maxIndex - minIndex +1;
        
        
    }
};

// 1 3 5 2 4 6 7 8 2 3
// 2,6,8,4,10,9,15
// largest possible inversion 
