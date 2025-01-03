#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        string ans = "";
        int correct = 0;
        map<int,int> mpSecret;
        map<int,int> mpGuess;
        for(int i = 0 ; i < n ; i++){
            if(secret[i] == guess[i]) correct++;
            else{
                mpSecret[secret[i] - '0']++;
                mpGuess[guess[i] - '0']++;
            }
        }
        ans += to_string(correct);
        ans += 'A';
        if(mpSecret == mpGuess){
            ans +=  to_string(n-correct);
            ans += 'B';
            return ans;
        }
        int cows = 0;
        for(auto it: mpSecret){
            int num = it.first;
            int cnt = it.second;
            if(mpGuess.find(num) != mpGuess.end()){
                if(mpGuess[num] >= cnt){
                    cows += cnt;
                }
                else cows += mpGuess[num];
            }
        }
        ans += to_string(cows);
        ans += 'B';
        return ans;
    }
};
int main(){
    Solution s;
    string secret = "1807"; 
    string guess = "7810";
    cout<<s.getHint(secret,guess)<<endl;
    return 0;
}