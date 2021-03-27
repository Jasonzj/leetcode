/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode* pre = nullptr;
    TreeNode* t1 = nullptr;
    TreeNode* t2 = nullptr;
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                
                // 如果原来的顺序是[1, 2, 3, 4, 5, 6, 7]
                // 两个节点交换之后[1, 6, 3, 4, 5, 2, 7]
                // 第一次是 6 > 3, 我们需要记住6
                if (pre && pre->val >= root->val) {
                    if (!t1) {
                        t1 = pre;
                    }
                    // 第二次是 5 > 2
                    // 此时需要记住2
                    t2 = root;
                }
                
                pre = root;
                
                root = root->right;
            }
        }
        
        int temp = t1->val;
        t1->val = t2->val;
        t2->val = temp;
    }
};
// @lc code=end

