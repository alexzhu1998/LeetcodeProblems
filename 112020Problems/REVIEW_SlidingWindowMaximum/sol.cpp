class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0) return res;
        priority_queue<int> heap;
        priority_queue<int> to_pop;
        for (int i = 0; i < k; i++) heap.push(nums[i]);
        res.push_back(heap.top());
//         initialise the deque
//         add as many elements into the deque, only add the maximum (including duplicates)
//         vector <int> vect2;
//         vect2.assign(nums.begin(),nums.begin()+k-1);
        
//         make_heap(vect2.begin(),vect2.end());
        
        // for (int i = 1; i < k+1; i++) {
        //     // if (nums[i] > Q.front()) {
        //     //     clear(Q);
        //     //     Q.push_back(nums[i]);
        //     // } else if (nums[i] == Q.front()) {
        //     //     Q.push_back(nums[i]);
        //     // }
        //     Q.push_back(nums[i]);
        //     // for (auto q:Q) {
        //     //     std::cout << q << " ";
        //     // }
        //     // std::cout<<std::endl;
        // }
//         iterate through the vector
        for (int i = k; i < nums.size(); i++) {
//             add elements into res based on the top value of the heap
//             pop elements by the top value of the heap
            if (heap.top() == nums[i-k]) {
                heap.pop();
            } else {
                to_pop.push(nums[i-k]);
            }
            while (!to_pop.empty() && to_pop.top() == heap.top()) {
                to_pop.pop();
                heap.pop();
            }
            heap.push(nums[i]);
            res.push_back(heap.top());
        }
        return res;
    }
    
};

#include <deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        std::deque<pair<int, int> > q; // number, position;
        
        int i=0; 
        for(;i<k; i++)
        {
            if(q.empty())
                q.push_back(pair<int, int>(nums[i],i));
            else
            {
                while(!q.empty())
                {
                    pair<int, int> topper = q.back();
                    if(topper.first <= nums[i])
                    {
                        q.pop_back();
                    }
                    else
                        break;
                }
                q.push_back(pair<int, int>(nums[i],i));
            }
        }
        
        std::vector<int> ans;
        ans.push_back(q.front().first);
        //std::cout<<ans[0]<<"\n";
        for(; i < nums.size(); i++)
        {
            //std::cout<<"value of i is: "<<i<<"\n";
            while(!q.empty())
            {
                pair<int, int> topper = q.back();
                    if(topper.first <= nums[i])
                    {
                        q.pop_back();
                    }
                    else
                        break;
            }
            q.push_back(pair<int, int>(nums[i],i));
            
            while(!q.empty())
            {
                 pair<int, int> topper = q.front();
                int topper_location = topper.second;
                if(i- topper_location >= k)
                    q.pop_front();
                else
                    break;
            }
            ans.push_back(q.front().first);
            
            
        }
        return ans;
                
        
    }
    
};

// Find Median of sliding window in an array.
// Smallest Window that contains all character of the string itself.
// Count Distinct Elements in every window of size K.
// Maximum and Minimum in the window of a given size in an array