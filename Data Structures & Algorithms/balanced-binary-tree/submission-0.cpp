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
    bool status=true;
    int getHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(l-r > 1 || r-l >1) {
            status = false;
        }
        return 1+max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return status;
    }
};
