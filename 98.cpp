/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (!root) return false;

        stack<pair<TreeNode*, pair<int64_t, int64_t>>> s;
        s.push({root, {INT64_MIN, INT64_MAX}});

        while (!s.empty()) {
            auto cur = s.top();
            auto node = cur.first;
            auto l = cur.second.first;    
            auto r = cur.second.second;    
            s.pop();
            
            if (!(l < node->val && node->val < r)) {
                return false;
            }

            if (node->right) s.push({node->right, {node->val, r}});
            if (node->left) s.push({node->left, {l, node->val}});
        }

        return true;
    }
};
// @lc code=end

