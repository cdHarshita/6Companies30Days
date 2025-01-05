#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> rects;
    vector<int> cum_sum; // Cumulative number of points up to each rectangle
    long long num_pts;

public:
    Solution(vector<vector<int>>& rects) {
        num_pts = 0;
        this->rects = rects;

        // Precompute the cumulative sums of points for each rectangle
        for (const auto& rect : rects) {
            int x_pts = rect[2] - rect[0] + 1;
            int y_pts = rect[3] - rect[1] + 1;
            num_pts += x_pts * y_pts;
            cum_sum.push_back(num_pts);
        }
    }

    vector<int> pick() {
        // Generate a random point index in the range [0, num_pts - 1]
        int pt_idx = rand() % num_pts;

        // Find the rectangle containing this point using binary search
        int start = 0, end = cum_sum.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (cum_sum[mid] <= pt_idx) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Rectangle index is `start`
        vector<int> rect = rects[start];
        int x_pts = rect[2] - rect[0] + 1;
        int y_pts = rect[3] - rect[1] + 1;

        // Calculate the point offset within the rectangle
        int pts_in_rect = x_pts * y_pts;
        int pt_start = cum_sum[start] - pts_in_rect;
        int offset = pt_idx - pt_start;

        // Compute the x and y coordinates of the point
        int x = rect[0] + offset % x_pts;
        int y = rect[1] + offset / x_pts;

        return {x, y};
    }
};

int main(){
    vector<vector<int>> rects = {{-2,-2,-1,-1},{1,0,3,0}};
    Solution s(rects);
    for (int i = 0; i < 5; i++) {
        vector<int> point = s.pick();
        cout << "Random Point: (" << point[0] << ", " << point[1] << ")" << endl;
    }
    return 0;
}