#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void floydWarshall(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] != 1e9 && mat[k][j] != 1e9) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<int>> adj(26, vector<int>(26, 1e9)); // Initialize distances as 1e9

        // Set up adjacency matrix
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u][v] = min(adj[u][v], cost[i]); // Handle multiple edges
        }

        // Apply Floyd-Warshall algorithm
        floydWarshall(adj);

        int m = source.length();
        long long ans = 0;

        for (int i = 0; i < m; i++) {
            if (source[i] == target[i]) continue; // No cost if characters are the same
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (adj[u][v] == 1e9) {
                return -1; // If there's no path, return -1
            }

            ans += adj[u][v];
        }

        return ans;
    }
};
int main(){
    Solution s;
    string source = "abc";
    string target = "bcd";
    vector<char> original = {'a','b','c'};
    vector<char> changed = {'b','c','d'};
    vector<int> cost = {1,2,3};
    cout<<s.minimumCost(source,target,original,changed,cost)<<endl;
    return 0;
}