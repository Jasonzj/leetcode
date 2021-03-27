/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int res = 0;
        if (root) {
            q.push(root);
        }
        
        while (!q.empty()) {
            int qSize = q.size();
            res++;
            while (qSize--) {
                auto cur = q.front();
                q.pop();
                
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }

        return res;
    }
};
// @lc code=end

