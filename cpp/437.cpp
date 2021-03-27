/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    unordered_map<int, int> prefix_map;  // 前缀和map
public:
    void backtrace(TreeNode* root, int target, int sum, int &res) {
        if (!root) return;
        
        sum += root->val;       // 记录前缀和
            
        // 当前路径中存在以当前节点为终点的和为target的子路径
        if (prefix_map[sum - target]) {
            res += prefix_map[sum - target];
        }
        
        prefix_map[sum]++;      // 记录当前节点前缀和, 数量+1
            
        backtrace(root->left, target, sum, res);
        backtrace(root->right, target, sum, res);
        
        prefix_map[sum]--;      // 回溯
    }
    
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = 0;
        prefix_map[0] = 1;      // 处理路径包括根节点的情况 
        backtrace(root, sum, 0, res);
        return res;
    }
};
// @lc code=end

