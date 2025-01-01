#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));

        // Define directions for neighbors
        vector<int> dx = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        // Traverse through the image
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0, count = 0;

                // Check all 8 neighbors and the current cell
                for (int k = 0; k < 9; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    // Ensure the neighbor is within bounds
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += img[ni][nj];
                        count++;
                    }
                }

                // Update the result with the average
                result[i][j] = sum / count;
            }
        }

        return result;
    }
};
int main(){
    Solution s;
    vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> result = s.imageSmoother(img);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}