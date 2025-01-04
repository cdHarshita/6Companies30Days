#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        unordered_map<string,int> mpp;
        for(int i=0;i+10 <= s.length();i++){
            mpp[s.substr(i,10)]++;
        }

        for(auto& i:mpp){
            if(i.second > 1){
                v.push_back(i.first);
            }
        }

        return v;
        
    }
};
int main(){
    Solution s;
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> v = s.findRepeatedDnaSequences(str);
    for(auto i:v){
        cout<<i<<endl;
    }
    return 0;
}