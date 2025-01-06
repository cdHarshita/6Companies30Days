#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPalindrome(const string &s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // Recursive function to generate palindromic subsequences
    void generatePalindromicSubsequences(
        string &s, int index, string current, vector<int> &visited,
        vector<pair<string, vector<int>>> &palindromes) 
    {
        if (index == s.size()) {
            if (isPalindrome(current)) {
                palindromes.push_back({current, visited});
            }
            return;
        }

        // Include current character in the subsequence
        visited[index] = 1; // Mark the current index as visited
        generatePalindromicSubsequences(s, index + 1, current + s[index], visited, palindromes);
        visited[index] = 0; // Backtrack

        // Exclude current character from the subsequence
        generatePalindromicSubsequences(s, index + 1, current, visited, palindromes);
    }

    // Function to calculate the maximum product of lengths of two disjoint palindromic subsequences
    int maxProduct(string s) {
        int n = s.size();
        vector<int> visited(n, 0); // Track visited indices
        vector<pair<string, vector<int>>> palindromes; // {subsequence, visited array}

        // Generate all palindromic subsequences
        generatePalindromicSubsequences(s, 0, "", visited, palindromes);

        int maxProd = 0;

        // Compare all pairs of palindromic subsequences
        for (int i = 0; i < palindromes.size(); ++i) {
            for (int j = i + 1; j < palindromes.size(); ++j) {
                bool disjoint = true;

                // Check if the indices in the two subsequences are disjoint
                for (int k = 0; k < n; ++k) {
                    if (palindromes[i].second[k] && palindromes[j].second[k]) {
                        disjoint = false;
                        break;
                    }
                }

                if (disjoint) {
                    int prod = palindromes[i].first.length() * palindromes[j].first.length();
                    maxProd = max(maxProd, prod);
                }
            }
        }

        return maxProd;
    }
};

int main(){
    Solution s;
    string str = "leetcodecom";
    cout<<s.maxProduct(str);
    return 0;
}