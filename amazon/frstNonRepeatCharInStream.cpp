#include<iostream>
#include<vector>
#include<map>
using namespace  std;
class Solution {
public:
    // int search(string s,char ch){
    //     for(int i=0 ; i<s.length() ; i++){
    //         if(s[i]==ch) return i;
    //     }
    //     return -1;
    // }
    int firstUniqChar(string s) {
        map<char,int> mp;
        for(int i=0 ; i<s.length() ; i++){
            mp[s[i]]++;
        }
        for(int i=0 ; i<s.length(); i++){
            if(mp[s[i]]==1) return i;
        }
        return -1;
    }
};
int main(){
   Solution s;
    string str = "leetcode";
    cout<<s.firstUniqChar(str)<<endl;
}