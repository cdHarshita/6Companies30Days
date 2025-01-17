#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//better approach
// #include <queue>
// vector<int> maxOfSubarrays(vector<int>& arr, int k) {
//     priority_queue<pair<int, int>> maxHeap; // Stores (value, index)
//     vector<int> result;

//     for (int i = 0; i < arr.size(); i++) {
//         // Insert the current element into the heap
//         maxHeap.push({arr[i], i});

//         // Remove elements outside the current window
//         while (maxHeap.top().second <= i - k) {
//             maxHeap.pop();
//         }

//         // Record the maximum for the current window
//         if (i >= k - 1) {
//             result.push_back(maxHeap.top().first);
//         }
//     }

//     return result;
// }
// // Time Complexity: O(n log k)
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int left = 0;               // Left pointer of the window
    int ans = INT_MIN;          // To track the maximum in the current window
    vector<int> rs;             // Result array to store maximums

    for (int right = 0; right < arr.size(); right++) {
        // Update the maximum for the current window
        ans = max(ans, arr[right]);

        // Check if the window size has reached `k`
        if (right - left + 1 == k) {
            rs.push_back(ans); // Add the maximum to the result array

            // If the maximum element is going out of the window, reset `ans`
            if (arr[left] == ans) {
                ans = INT_MIN; // Recompute the maximum for the next window
                for (int i = left + 1; i <= right; i++) {
                    ans = max(ans, arr[i]);
                }
            }

            // Slide the window
            left++;
        }
    }

    return rs;
}

int main(){
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> rs = maxOfSubarrays(arr, k);
    for (int i = 0; i < rs.size(); i++) {
        cout << rs[i] << " ";
    }
    return 0;
}