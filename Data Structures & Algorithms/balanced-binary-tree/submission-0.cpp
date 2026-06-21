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
    int helper(TreeNode* root,bool &ans) {
        if(!root) return 0;
        int h1 = helper(root->left,ans);
        int h2 = helper(root->right,ans);
        if(abs(h1-h2) > 1) ans = false;
        return max(h1,h2)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        helper(root,ans);
        return ans;
    }
};
