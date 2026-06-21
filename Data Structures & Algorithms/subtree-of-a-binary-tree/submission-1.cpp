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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;

        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(root->val == subRoot->val && isSameTree(root,subRoot)) return true;

        return helper(root->left,subRoot) || helper(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
    }
};
