/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* preOrder(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        
        root1->val += root2->val;
        
        root1->left = preOrder(root1->left, root2->left);
        root1->right = preOrder(root1->right, root2->right);
        
        return root1;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return preOrder(root1, root2);
    }
};
// @lc code=end

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({root1, root2});
        
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            auto node1 = cur.first;
            auto node2 = cur.second;
            
            // 两个都存在相加
            if (node1 && node2) node1->val += node2->val;

            // 两个都存在入栈
            if (node1->right && node2->right) s.push({node1->right, node2->right});
            if (node1->left && node2->left) s.push({node1->left, node2->left});
            
            // node1不存在的子树用node2的子树填充
            if (!node1->left && node2->left) node1->left = node2->left;
            if (!node1->right && node2->right) node1->right = node2->right;
        }
        
        return root1;
    }
};