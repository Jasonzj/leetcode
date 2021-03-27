/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void backtrace(TreeNode* root, int64_t target, int64_t sum, vector<int> &path, vector<vector<int>> &res) {
        if (!root) return;

        path.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right) {
            if (sum == target) { 
                res.push_back(path);
            }
        } else {
            backtrace(root->left, target, sum, path, res);
            backtrace(root->right, target, sum, path, res);
        }

        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<int> path;
        vector<vector<int>> res;
        backtrace(root, sum, 0, path, res);
        return res;
    }
};
// @lc code=end

