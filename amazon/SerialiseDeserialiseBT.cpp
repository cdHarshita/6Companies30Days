#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";  // If the tree is empty, return '#'
        
        string result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                result += to_string(node->val) + " ";  // Use space as delimiter
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "# ";  // Add null marker
            }
        }
        
        // Remove the last unnecessary space
        if (!result.empty()) result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;  // If the data is just '#', it's an empty tree

        // Split the data string by spaces to get individual node values
        stringstream ss(data);
        string item;
        getline(ss, item, ' ');
        
        // Create the root node
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);

        // Process remaining node values
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Process left child
            if (getline(ss, item, ' ')) {
                if (item == "#") {
                    node->left = nullptr;
                } else {
                    node->left = new TreeNode(stoi(item));
                    q.push(node->left);
                }
            }

            // Process right child
            if (getline(ss, item, ' ')) {
                if (item == "#") {
                    node->right = nullptr;
                } else {
                    node->right = new TreeNode(stoi(item));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};
int main(){
    Codec codec;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized: " << codec.serialize(deserialized) << endl;

    return 0;
}