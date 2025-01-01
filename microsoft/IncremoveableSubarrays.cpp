#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isIncreasing(vector<int>& nums, int prev, int next) {
        // Check if elements before `prev` are strictly increasing
        for (int i = 0; i < prev; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        // Check if elements after `next` are strictly increasing
        for (int i = next; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        // Check boundary condition between `prev` and `next`
        if (prev >= 0 && next < nums.size() && nums[prev] >= nums[next]) return false;
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        // Iterate over all subarrays
        for (int i = 0; i < n; i++) {           // Starting index of subarray
            for (int prev = i - 1; prev >= -1; prev--) { // End of the valid subarray
                if (isIncreasing(nums, prev, i + 1)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout<<s.incremovableSubarrayCount(nums)<<endl;
    return 0;
}