#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int solve(vector<int>& nums,int val){
//         if(find(nums.begin(),nums.end(),val) == nums.end())  return -1;
//         int cost = 0;
//         for(int ele : nums){
//             cost +=  val > ele ? (val - ele) : (ele -val);
//         }
//         cout<<cost<<endl;
//         return cost;
//     }
//     int minMoves2(vector<int>& nums) {
//         int start = *min_element(nums.begin(),nums.end());
//          int end = *max_element(nums.begin(),nums.end());
//         int ans = INT_MAX;
//         while(start <= end){
//             int mid = start + (end - start)/2;
//             cout<<mid<<" ";
//             int see = solve(nums,mid);
//             // cout<<see<<endl;
//             if(see != -1 && see < ans){
//                 ans  = see;
//                 end = mid - 1;
//             }
//             else{
//                 start = mid + 1;
//             }
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };
// min value -----> max value 
// mid value --> approach ki agar uss value ko bna skte hain uss se lower ke liye find krenge

//This approach was not working because whatever search space we are taking it is not necessary that we will get the answer in that search space
// we dont have certainity of answer in that search space so we need to drop that approach


//what we can do more simpler that 
// we can greedily think that if we make every no equal to median of the array
// then we can get the minimum cost
// we can sort the array and then we can find the median of the array
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //median of the array
        int median = nums[nums.size()/2];
        int moves = 0;
        for(int num : nums){
            moves += (abs(num - median));
        }
        return moves;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    cout<<s.minMoves2(nums);
    return 0;
}