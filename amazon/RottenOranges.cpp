#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=-1,freshCnt=0;
        queue<pair<int,int>> q;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j]==1) freshCnt++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        if (freshCnt == 0) return 0;

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        while(!q.empty()){
            int size=q.size();
            ans++;
            while(size--){
                auto top=q.front();
                int i=top.first;
                int j=top.second;
                q.pop();
                for(int ind=0 ; ind<4 ; ind++){
                    int nrow=i+dx[ind];
                    int ncol=j+dy[ind];
                    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        freshCnt--;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return freshCnt==0 ? ans : -1 ;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    cout<<s.orangesRotting(grid)<<endl;
    return 0;
}