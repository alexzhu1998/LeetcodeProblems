#include <vector>
#include <string>

class Solution 
{
private:
    bool isPalindrome(const std::string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::vector<std::string>> partitions;
        std::vector<std::string> partition;
        this->accumulatePartitions(s, 0, partition, partitions);
        return partitions;
    }
    
    void accumulatePartitions(const std::string& s, int step,
                              std::vector<std::string>& partition, std::vector<std::vector<std::string>>& partitions)
    {
        if (step == s.size())
        {
            partitions.push_back(partition);
            return;
        }
        
        int left = step;
        for (int right = left; right < s.size(); right++)
        {
            if (this->isPalindrome(s, left, right))
            {
                partition.push_back(s.substr(left, right - left + 1));
                this->accumulatePartitions(s, right + 1, partition, partitions);
                partition.pop_back();
            }
        }
        
    }
};
