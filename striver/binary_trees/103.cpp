#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {} // Proper initialization
};

// Function to perform level-order traversal
vector<vector<int>> zigZagTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool lTr = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            int idx = lTr ? i:(size - 1- i );

            level[idx] = node->val;
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        lTr = !lTr;
        ans.push_back(level);
    }
    return ans;
}

// Function to deallocate the tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Create the tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Get level-order traversal
    vector<vector<int>> arr = zigZagTraversal(root);

    // Print all nodes at each level
    for (const auto& level : arr) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << ","; // Newline after each level for clarity
    }

    // Clean up memory
    deleteTree(root);

    return 0;
}