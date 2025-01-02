#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> visited(n + 1,false);
        int cnt = 0;
        int idx = 1;
        while (cnt < n - 1){
            int vis = 0;
            int i = idx;
            for( ;   ; i++){
                if(!visited[i % n]){
                    vis ++;
                }
                if(vis == k) break;
            }
            // cout<<i%n<<" ";
            visited[ i% n] = true;
            idx = (i % n + 1);
            cnt++;
        }
        for(int i = 1  ; i <= n ; i++){
            if(!visited[i]) return i;
        }
        return - 1;
    }
};
int main(){
    Solution s;
    int n = 5;
    int k = 2;
    cout<<s.findTheWinner(n,k)<<endl;
    return 0;
}