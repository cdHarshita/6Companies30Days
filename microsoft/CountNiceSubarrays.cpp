#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, count = 0, track = 0, prefix = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 != 0) {
                track++;
                prefix = 0;  // Reset prefix count when a new odd number is found
            }

            while (track == k) {
                // Count subarrays starting from current `left`
                if (nums[left] % 2 != 0) track--;
                prefix++;
                left++;
            }

            count += prefix;
        }

        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout<<s.numberOfSubarrays(nums,k)<<endl;
    return 0;
}