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
    int checkMaxValue(TreeNode* root, int maxValue){
        if(root == nullptr) return 0;
        maxValue = max(maxValue, root->val);
        int leftGoodNodes = checkMaxValue(root->left, maxValue);
        int rightGoodNodes = checkMaxValue(root->right, maxValue);
        if(root->val >= maxValue){
            return 1+leftGoodNodes+rightGoodNodes;
        }
        return leftGoodNodes+rightGoodNodes;
    }
    int goodNodes(TreeNode* root) {
       int left= root->left ==nullptr ? 0 :checkMaxValue(root->left, root->val);
       int right = root->right ==nullptr ? 0 : checkMaxValue(root->right, root->val);
       return 1+left+right;
    }
};
