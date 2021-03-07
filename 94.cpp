/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s; 
        TreeNode* cur = root;

        while (cur != NULL || !s.empty()) {
            if (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
                cur = cur->right; 
            }
        }

        return res;
    }
}
// @lc code=end

class Solution {
public:
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        inorder(node->left, res); 
        res.push_back(node->val);
        inorder(node->right, res); 
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; 
        if (!root) return res;
        inorder(root, res);
        return res;
    }
};
