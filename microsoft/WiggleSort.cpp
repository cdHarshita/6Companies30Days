#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         int n = nums.size();
//         if(nums[0] > nums[n-1]) swap(nums[0],nums[n-1]);
//         for(int i = 0 ; i < n ; i++){
//             if(i % 2 != 0){
//                 if(i+1 < n && nums[i] < nums[i+1]){
//                     swap(nums[i],nums[i+1]);
//                 }
//             }else{
//                 if(i+1 < n && nums[i] > nums[i+1]){
//                     swap(nums[i], nums[i+1]);
//                 }
//             }
//         }
//     }
// };
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n= nums.size();
        priority_queue<int> q(nums.begin(), nums.end());
        for(int i=1; i<n; i += 2){
            nums[i] = q.top();
            q.pop();
        }
        for(int i=0; i<n; i += 2){
            nums[i] = q.top();
            q.pop();
        }
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,5,1,1,6,4};
    s.wiggleSort(nums);
    for(auto i: nums){
        cout<<i<<" ";
    }
    return 0;
}