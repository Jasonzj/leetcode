/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
// 左数区间[p_start, p_end), 右数区间[i_start, i_end)
class Solution {
    TreeNode* _buildTree(vector<int> &preorder, int p_start, int p_end, vector<int> &inorder, int i_start, int i_end, unordered_map<int, int> &map) {
        if (p_start >= p_end) return nullptr;
        
        int cur = preorder[p_start];        
        TreeNode* root = new TreeNode(cur);
        int pos = map[cur];                 // 拿到中序数组中根节点的位置
        int leftNum = pos - i_start;        // 计算中序数组头到根节点长度

        root->left = _buildTree(preorder, p_start + 1, p_start + leftNum + 1, inorder, i_start, pos - 1, map);
        root->right = _buildTree(preorder, p_start + leftNum + 1, p_end, inorder, pos + 1, i_end, map);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return _buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size(), map);
    }
};
// @lc code=end
