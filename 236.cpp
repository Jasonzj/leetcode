/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    TreeNode* res = nullptr;
    bool postOrder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;

        int lcnt = postOrder(root->left, p, q);
        int rcnt = postOrder(root->right, p, q);

        if (lcnt && rcnt) {
            res = root;
        } else if (lcnt || rcnt) {
            if (root == p || root == q) {
                res = root;
            }
        }

        return lcnt || rcnt || root == p || root == q;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        postOrder(root, p, q);
        return res;
    }
};
// @lc code=end

