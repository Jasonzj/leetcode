/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
 /*
 对任意一个节点，如果最大路径和包括这个节点，则有两种情况:
 1. 该节点的左右子树中所构成的路径值较大的那个加上该节点的值向父节点累加构成最大路径
 2. 该节点左右子树都在最大路径中， 加上该节点的值构成了最大路径
 */
class Solution {
    int postOrder(TreeNode* root, int &res) {
        if (!root) return 0;

        int left = max(0, postOrder(root->left, res));  // 如果子树路径和为负则置0，表示最大路径不包子树
        int right = max(0, postOrder(root->right, res));

        res = max(res, root->val + left + right);  // 当前节点的值加左右子树的路径和挑战当前最大路径和

        // 向父节点提供当前值加左右子树路径和较大的子树的路径和
        // 根+左+右不能向上累加，否则会路径分叉
        return max(left, right) + root->val;       
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        postOrder(root, res);
        return res;
    }
};
// @lc code=end

