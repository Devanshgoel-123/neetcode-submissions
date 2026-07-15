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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while(!q.empty()) {
            int n= q.size();
            int element = INT_MIN;
            for(int i=0; i < n; i++) {
                TreeNode* node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                element = node->val;
                q.pop();
            }
            if(element != INT_MIN) temp.push_back(element);
        }
        return temp;
    }
};
