/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, __uint128_t>> q;
        __uint128_t res = 0;
        if (root) {
            q.emplace(root, 0);
        }

        while (!q.empty()) {
            int qSize = q.size();
            res = max(res, q.back().second - q.front().second + 1);

            while (qSize--) {
                auto cur = q.front();
                q.pop();

                // 左节点编号为父节点编号x * 2
                // 右节点编号为父节点编号x * 2 + 1
                if (cur.first->left) q.emplace(cur.first->left, cur.second << 1);
                if (cur.first->right) q.emplace(cur.first->right, (cur.second << 1) + 1);
            }      
        }

        return res;
    }
};
// @lc code=end

