#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e9));
        for(auto &edge:edges){
            adj[edge[0]][edge[1]]=edge[2];
            adj[edge[1]][edge[0]]=edge[2];
        }
        for(int i=0 ; i<n ; i++){
            adj[i][i]=0;
        }
        for(int via=0 ; via<n ; via++){
            for(int i=0 ; i<n ; i++){
                if(i==via) continue;
                for(int j=0 ; j<n ; j++){
                    if(j==via) continue;
                    adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        map<int,int> mp; 
        int mini=n;
        int ans=0;
        for(int i=0 ; i<n ; i++){
            int cnt=0;
            for(int j=0 ; j<n ; j++){
                if(i!=j && adj[i][j]<=distanceThreshold)cnt++;
            }
            if(cnt<=mini){
                ans=i;
            }
            mini=min(mini,cnt);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> edges={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout<<s.findTheCity(4,edges,4)<<endl;
    return 0;
}