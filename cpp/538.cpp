/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* head = root;
        int sum = 0;
        
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->right;
            }
            root = s.top();
            s.pop();

            sum += root->val;
            root->val = sum;
            
            root = root->left;
        }
        
        return head;
    }
};
// @lc code=end

class Solution {
    int sum = 0;
    void inOrder(TreeNode* root) {
        if (!root) return;

        inOrder(root->right);

        sum += root->val;
        root->val = sum; 

        inOrder(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        inOrder(root);
        return root;
    }
};