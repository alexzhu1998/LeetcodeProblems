#include <iostream>
#include <vector>
using namespace std;


int main() {
    int target = 9;
    vector<int> nums = {-1,0,3,5,9,12};

    int l,r;
    l = 0;
    r = nums.size();
    
    int mid;
    while (l <= r) {
        mid = l + (r-l)/2;
        if (nums[mid]  == target) {
            cout << mid << endl;
            return 0;
        } else if (nums[mid] > target) {
            r = mid -1; 
        } else {
            l = mid +1;
        }
    }
    cout << -1 << endl;
    return 0;
}