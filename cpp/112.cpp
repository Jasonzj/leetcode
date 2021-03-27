/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        stack<pair<TreeNode*, int>> s;
        if (root) s.push({root, 0});
        
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            TreeNode* curNode = cur.first;
            int curSum = cur.second;
            curSum += curNode->val;
            
            if (!curNode->left && !curNode->right) {
                if (curSum == sum) {
                    return true;
                }
            }
            
            if (curNode->right) s.push({curNode->right, curSum});
            if (curNode->left) s.push({curNode->left, curSum});
        }
        
        return false;
    }
};
// @lc code=end


class Solution {
    void preOrder(TreeNode* root, int sum, int pathSum, bool &res) {
        if (!root) return;
        
        pathSum += root->val;
        
        if (!root->left && !root->right) {
            if (pathSum == sum) {
                res = true;
            }
        } else {
            preOrder(root->left, sum, pathSum, res);
            preOrder(root->right, sum, pathSum, res);
        }
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool res = false;
        preOrder(root, sum, 0, res);
        return res;
    }
};