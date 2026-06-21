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
    void findNode(TreeNode* root, int key, TreeNode*& pr, TreeNode*& child) {
        if (!root) return;

        if (root->left) {
            if (root->left->val == key) {
                pr = root;
                child = root->left;
            }
        }
        if (root->right) {
            if (root->right->val == key) {
                pr = root;
                child = root->right;
            }
        }
        findNode(root->left, key, pr, child);
        findNode(root->right, key, pr, child);
        return;
    }
    int findmin(TreeNode* root) {
        if (!root) return 0;
        while (root->left) root = root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            } else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                int mini = findmin(root->right);
                root->val = mini;
                root->right = deleteNode(root->right, mini);
            }
        } else {
            TreeNode *pr = NULL, *child = NULL;
            findNode(root, key, pr, child);
            if (!child) return root;
            if (!child->left && !child->right) {
                if (pr->left == child) pr->left = NULL;
                if (pr->right == child) pr->right = NULL;
                delete child;
            } else if (!child->left) {
                if (pr->left == child) pr->left = child->right;
                if (pr->right == child) pr->right = child->right;
                delete child;
            } else if (!child->right) {
                if (pr->left == child) pr->left = child->left;
                if (pr->right == child) pr->right = child->left;
                delete child;
            } else {
                int mini = findmin(child->right);
                child->val = mini;
                child->right = deleteNode(child->right, mini);
            }
        }
        return root;
    }
};