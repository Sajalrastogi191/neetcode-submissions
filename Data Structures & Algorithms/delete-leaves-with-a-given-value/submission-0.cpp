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
    bool isleaf(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        return false;
    }
    TreeNode* helper(TreeNode* root, int target,int &cnt) {
        if(!root) return NULL;
        root->left = helper(root->left,target,cnt);
        root->right = helper(root->right,target,cnt);
        if(isleaf(root) && root->val == target) {
            cnt = 1;
            return nullptr;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        while(true) {
            int cnt = 0;
            root = helper(root,target,cnt);
            if(cnt == 0) {
                return root;
            }
        }
        return nullptr;
    }
};