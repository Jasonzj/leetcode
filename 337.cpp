/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> postOrder(TreeNode* root) {
        vector<int> result(2);
        if (!root) return result;

        vector<int> left = postOrder(root->left);
        vector<int> right = postOrder(root->right);

        // 当前节点选择不偷: 左右孩子节点选择偷和不偷的最大值相加
        result[0] = max(left[0], left[1]) + max(right[0], right[1]); 
        // 当前节点选择偷: 左右孩子选择不偷 + 当前节点值
        result[1] = left[0] + right[0] + root->val; 

        return result;
    }
public:
    int rob(TreeNode* root) {
        vector<int> result = postOrder(root);
        return max(result[0], result[1]);
    }
};
// @lc code=end

