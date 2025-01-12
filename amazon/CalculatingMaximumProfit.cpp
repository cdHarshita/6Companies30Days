#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int solve(int ind, int buy, int cnt, vector<int>& prices, int &n, int &k,vector<vector<vector<int>>> &dp) {
        if (ind == n || cnt == k) {
            return 0;  
        }
        if (dp[ind][buy][cnt] != -1) {
            return dp[ind][buy][cnt];
        }

        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + solve(ind + 1, 0, cnt, prices, n, k,dp), solve(ind + 1, 1, cnt, prices, n,k, dp));
        } else {
           profit = max(prices[ind] + solve(ind + 1, 1, cnt + 1, prices, n,k, dp), solve(ind + 1, 0, cnt, prices, n,k, dp));
        }
        return dp[ind][buy][cnt] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return solve(0,1,0,prices,n,k,dp);
    }
};
int main(){
    Solution s;
    vector<int> prices={2,4,1};
    cout<<s.maxProfit(2,prices)<<endl;
    return 0;
}