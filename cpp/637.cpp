/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        if (root) {
            q.push(root);
        }
        
        while (!q.empty()) {
            int qSize = q.size();
            int num = qSize; 
            double sum = 0;

            while (qSize--) {
                auto cur = q.front();
                q.pop();

                sum += cur->val;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            res.push_back(sum / num);
        }

        return res;
    }
};
// @lc code=end

