/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int qSize = q.size();
            res.emplace_back();

            while (qSize--) {
                auto cur = q.front();
                q.pop();

                res.back().push_back(cur->val);

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

