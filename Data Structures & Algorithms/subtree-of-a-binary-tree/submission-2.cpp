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
    int checkMatch(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return 1;
        if (p == nullptr || q == nullptr) return -1;
        if (p->val != q->val) return -1;
        int left = checkMatch(p->left, q->left);
        if(left == -1) return -1;
        int right = checkMatch(p->right, q->right);
        if(right == -1) return -1;
        return 1;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr || subRoot == nullptr) return false;
        if(root->val == subRoot->val && checkMatch(root, subRoot) ==1) return true;
        bool left = isSubtree(root->left, subRoot);
        if( left) return true;
        bool right = isSubtree(root->right, subRoot);
        if( right ) return true;
        return false;
    }
};
