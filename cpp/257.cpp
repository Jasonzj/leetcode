/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        stack<pair<TreeNode*, string>> s;
        s.push({root, ""});
        
        while (!s.empty()) {
            auto cur = s.top();
            auto node = cur.first;
            auto path = cur.second;
            s.pop();
            
            path += to_string(node->val);
            
            if (!node->right && !node->left) {
                res.push_back(path);
            }
            
            if (node->right) s.push({node->right, path + "->"});
            if (node->left) s.push({node->left, path + "->"});
        }
        
        return res;
    }
};
// @lc code=end


class Solution {
    void preOrder(TreeNode* root, vector<string> &res, string path) {
        if (!root) return;

        path += to_string(root->val);

        if (!root->left && !root->right) {
            res.push_back(path);
        }

        if (root->left) preOrder(root->left, res, path + "->");
        if (root->right) preOrder(root->right, res, path + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        preOrder(root, res, "");
        return res;
    }
};
