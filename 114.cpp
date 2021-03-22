/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
 // 后序变形 右左中
class Solution {
    TreeNode* last = nullptr;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;
        last = root;
    }
};
// @lc code=end
