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
    int recursiveTravel(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return 1;
        if (p == nullptr || q == nullptr) return -1;
        if(p->val != q->val) return -1;
        int left = recursiveTravel(p->left, q->left);
        if(left == -1) return -1;
        int right = recursiveTravel(p->right, q->right);
        if(right == -1) return -1;
        return 1;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int match = recursiveTravel(p, q);
        return match != -1;
    }
};
