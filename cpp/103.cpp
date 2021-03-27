/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> cur;
        vector<TreeNode*> next;
        vector<vector<int>> res;
        bool isReverse = false;
        if (root) {
            cur.push_back(root);
        }

        while (!cur.empty()) {
            res.emplace_back();
            next.clear();

            for (auto n : cur) {
                res.back().push_back(n->val);

                if (n->left) next.push_back(n->left);
                if (n->right) next.push_back(n->right);
            }

            if (isReverse) reverse(res.back().begin(), res.back().end());
            isReverse = !isReverse;

            swap(cur, next);
        }

        return res;
    }
};
// @lc code=end

