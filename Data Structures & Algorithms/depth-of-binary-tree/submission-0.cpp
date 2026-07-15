/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int traversal(TreeNode* root, int currentDepth, int maxD) {
        if(root == nullptr) return currentDepth;
        int left = traversal(root->left, currentDepth+1, maxD);
        int right = traversal(root->right, currentDepth+1, maxD);
        maxD = max(maxD, max(left, right));
        return maxD;
    }
    int maxDepth(TreeNode* root) {
        int maxD = 0;
        return traversal(root, 0, maxD);
    }
};
