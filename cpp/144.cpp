/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (!root) return res;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }

        return res;
    }
};
// @lc code=end


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (!root) return res;
        TreeNode* cur = root;

        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            cur = cur->right;
        }

        return res;
    }
};