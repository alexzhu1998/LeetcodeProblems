class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = nums.back();
        int m;
        while (l < r) {
            m = l + (r-l)/2;
            if (div(nums,m) <= threshold) {
                r = m;
            } else {
                l = m+1;
            }
            
            // std::cout << div(nums,m) << " "<< m << std::endl;
        }
        return r;
    }
    int div(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]%divisor == 0) {
                sum += nums[i]/divisor;
            } else {
                sum += nums[i]/divisor + 1;
            }
            // std::cout << nums[i]/divisor << std::endl;
            
        }
        return sum;
    }
};

