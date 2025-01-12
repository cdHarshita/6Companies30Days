#include<iostream>
#include<map>
using namespace std;

int main(){
    string s = "abcdefggh";  // Example input string
    int left = 0, count = 0;
    map<char, int> mp;

    // Iterate through the string with the right pointer
    for (int right = 0; right < s.length(); right++) {
        mp[s[right]]++;

        // If the window exceeds size 4, move the left pointer
        while (right - left + 1 > 4) {
            mp[s[left]]--;
            if (mp[s[left]] == 0) {
                mp.erase(s[left]);
            }
            left++;
        }

        // If the window has exactly size 4 and all characters are unique, count it
        if (right - left + 1 == 4 && mp.size() == 4) {
            cout << s.substr(left, 4) << endl;  // Print the valid 4-character substring
            count++;
        }
    }

    // Output the total count of substrings with unique characters
    cout << count << endl;
}
// #include <iostream>
// #include <queue>
// using namespace std;

// // Define the structure for a Binary Tree node
// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     // Constructor for easy creation of nodes
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// // Function to take input for the tree using level order traversal
// Node* buildTree() {
//     int val;
//     cout << "Enter the level order traversal of the tree (-1 for NULL):" << endl;

//     // Take the first node as the root
//     cin >> val;
//     if (val == -1) {
//         return nullptr; // If the root is -1, the tree is empty
//     }

//     // Create the root node
//     Node* root = new Node(val);

//     // Use a queue to construct the tree
//     queue<Node*> q;
//     q.push(root); // Push the root node to the queue

//     while (!q.empty()) {
//         Node* current = q.front();
//         q.pop();

//         // Read and process the left child
//         cin >> val;
//         if (val != -1) { // If it's not -1, create a left child
//             current->left = new Node(val);
//             q.push(current->left);
//         }

//         // Read and process the right child
//         cin >> val;
//         if (val != -1) { // If it's not -1, create a right child
//             current->right = new Node(val);
//             q.push(current->right);
//         }
//     }

//     return root;
// }

// // Function for Level Order Traversal (to display the tree)
// void levelOrderTraversal(Node* root) {
//     if (root == nullptr) {
//         return; // If the tree is empty, return
//     }

//     // Create a queue to store nodes of the tree
//     queue<Node*> q;
//     q.push(root); // Push the root node to start the traversal

//     while (!q.empty()) {
//         // Pop the front node of the queue
//         Node* current = q.front();
//         q.pop();

//         // Print the node's data
//         cout << current->data << " ";

//         // If the current node has a left child, add it to the queue
//         if (current->left != nullptr) {
//             q.push(current->left);
//         }

//         // If the current node has a right child, add it to the queue
//         if (current->right != nullptr) {
//             q.push(current->right);
//         }
//     }
//     cout << endl;
// }

// // Main function to test the Level Order Tree Input and Traversal
// int main() {
//     // Build the tree from level order input
//     Node* root = buildTree();

//     // Perform level order traversal and display the tree
//     cout << "Level Order Traversal of the tree: ";
//     levelOrderTraversal(root);

//     return 0;
// }
