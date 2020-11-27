class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};
    
// dfs in python
// class Solution(object):
//     def canPartition(self, nums):
//         """
//         :type nums: List[int]
//         :rtype: bool
//         """
//         sum_val = sum(nums)
//         if sum_val % 2 == 1:
//             return False
//         target = sum_val // 2
//         dp = [False] * (sum_val + 1)
//         dp[0] = True
//         for num in nums:
//             next_dp = [False] * (sum_val + 1)
//             for j in xrange(len(dp)):
//                 if dp[j]:
//                     next_dp[j + num] = True
//                     next_dp[j] = True
//             dp = next_dp
//         return dp[target]

