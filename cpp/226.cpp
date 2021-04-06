/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void postOrder(TreeNode* root) {
        if (!root) return;
        
        postOrder(root->left);
        postOrder(root->right);
        
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        postOrder(root);
        return root;
    }
};
// @lc code=end

class Solution {
    void preOrder(TreeNode* root) {
        if (!root) return;
        
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        preOrder(root->left);
        preOrder(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        preOrder(root);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            int qSize = q.size();

            while (qSize--) {
                auto cur = q.front();
                q.pop();
                
                auto tmp = cur->left;
                cur->left = cur->right;
                cur->right = tmp;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->left);
            }
        }

        return root;
    }
}