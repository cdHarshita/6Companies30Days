#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// User function Template for C++
class TrieNode {
public:
    char value;
    TrieNode* children[26]; // Array to store children nodes (a-z)
    bool isTerminal; // Marks the end of a word
    TrieNode(char ch) {
        value = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0'); // Root is a dummy node
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode(ch);
            }
            current = current->children[index];
        }
        current->isTerminal = true;
    }

    vector<string> search(string prefix) {
        TrieNode* current = root;
        vector<string> results;

        // Traverse the Trie to the end of the prefix
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!current->children[index]) {
                return {}; // Prefix not found
            }
            current = current->children[index];
        }

        // Perform DFS to find all words with the given prefix
        dfs(current, prefix, results);
        return results;
    }

private:
    void dfs(TrieNode* node, string prefix, vector<string>& results) {
        if (!node) return;
        if (node->isTerminal) {
            results.push_back(prefix); // Add the current word to the results
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                dfs(node->children[i], prefix + node->children[i]->value, results);
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // Create the Trie
        Trie trie;
        for (int i = 0; i < n; i++) {
            trie.insert(contact[i]);
        }

        vector<vector<string>> result;
        string prefix = "";

        // Generate results for each prefix of `s`
        for (char ch : s) {
            prefix += ch;
            vector<string> matches = trie.search(prefix);
            if (matches.empty()) {
                result.push_back({"0"}); // No match found
            } else {
                sort(matches.begin(), matches.end()); // Sort lexicographically
                result.push_back(matches);
            }
        }

        return result;
    }
};
int main(){
    int n = 5;
    string contact[] = {"gforgeeks", "geeksquiz", "geeksforgeeks", "geeks", "geek"};
    string s = "gekk";
    Solution obj;
    vector<vector<string>> result = obj.displayContacts(n, contact, s);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}