/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
 // 搜索树中序是有序的, 统计频率，和最大频率
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;  // 记录前一个指针
        int maxCount = 0;         // 最大频率
        int count = 0;            // 频率

        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;          // 左
            } else {
                root = s.top();
                s.pop();

                if (!pre) {                          // 处理第一个节点
                    count = 1;
                } else if (pre->val == root->val) {  // 相等频率++
                    count++;
                } else {                             // 不相等置1
                    count = 1;
                }

                pre = root;     // 记录节点

                if (count == maxCount) {
                    res.push_back(root->val);
                }
                if (count > maxCount) {
                    res.clear();
                    maxCount = count;
                    res.push_back(root->val);
                }

                root = root->right;     // 右
            }
        }

        return res;
    }
};
// @lc code=end

