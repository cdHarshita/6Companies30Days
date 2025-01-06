#include<iostream>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int digit;
        while (columnNumber > 0) {
            columnNumber--; // Adjust for 0-based indexing
            int digit = columnNumber % 26; // Get the current character's index
            char ch = 'A' + digit; // Convert to the corresponding character
            ans = ch + ans; // Prepend the character to the result
            columnNumber /= 26; // Move to the next "digit"
        }
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.convertToTitle(701)<<endl;
    return 0;
}