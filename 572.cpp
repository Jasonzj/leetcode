/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
// @lc code=end

class Solution {
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
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        stack<TreeNode*> h;
        if (s == t) return true;
        if (!s && t) return false;
        if (!t) return true;
        bool res = false;

        h.push(s);

        while (!h.empty()) {
            auto cur = h.top();
            h.pop();

            if (cur->val == t->val) res = isSameTree(cur, t);
            if (res) return res;

            if (cur->right) h.push(cur->right);
            if (cur->left) h.push(cur->left);
        }
        
        return res;
    }
};

