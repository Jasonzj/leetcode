/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> s;
        if (!p && !q) return true;
        
        s.push({p, q});
        
        while (!s.empty()) {
            auto cur = s.top();
            auto l = cur.first;
            auto r = cur.second;
            s.pop();
            
            if (!l && !r) continue;
            if (!l || !r) return false;
            if (l->val != r->val) return false;
            
            s.push({l->right, r->right});
            s.push({l->left, r->left});
        }
        
        return true;
    }
};
// @lc code=end

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

