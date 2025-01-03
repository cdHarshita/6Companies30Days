#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Check if a point is inside or on the circle
    bool insideOrOnCircle(int x, int y, int xCenter, int yCenter, int radius) {
        int distanceSquared = (x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter);
        return distanceSquared <= radius * radius;
    }

    // Check if a point is inside or on the rectangle
    bool insideOrOnRectangle(int x, int y, int x1, int y1, int x2, int y2) {
        int left = min(x1, x2);
        int right = max(x1, x2);
        int bottom = min(y1, y2);
        int top = max(y1, y2);
        return x >= left && x <= right && y >= bottom && y <= top;
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Check if the circle's center is inside the rectangle
        if (insideOrOnRectangle(xCenter, yCenter, x1, y1, x2, y2)) {
            return true;
        }

        // Check if any rectangle corner is inside or on the circle
        if (insideOrOnCircle(x1, y1, xCenter, yCenter, radius)) return true;
        if (insideOrOnCircle(x1, y2, xCenter, yCenter, radius)) return true;
        if (insideOrOnCircle(x2, y1, xCenter, yCenter, radius)) return true;
        if (insideOrOnCircle(x2, y2, xCenter, yCenter, radius)) return true;

        // Check if the circle intersects any rectangle edge
        int left = min(x1, x2);
        int right = max(x1, x2);
        int bottom = min(y1, y2);
        int top = max(y1, y2);

        // Check horizontal edges
        if (xCenter >= left && xCenter <= right) {
            if (abs(yCenter - bottom) <= radius || abs(yCenter - top) <= radius) return true;
        }

        // Check vertical edges
        if (yCenter >= bottom && yCenter <= top) {
            if (abs(xCenter - left) <= radius || abs(xCenter - right) <= radius) return true;
        }

        return false;
    }
};
int main(){
    Solution s;
    int radius = 1;
    int xCenter = 1;
    int yCenter = 1;
    int x1 = 1;
    int y1 = 1;
    int x2 = 2;
    int y2 = 2;
    cout<<s.checkOverlap(radius,xCenter,yCenter,x1,y1,x2,y2)<<endl;
    return 0;
}