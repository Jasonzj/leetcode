/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }

        vector<vector<int>> res; 

        while (!q.empty()) {
            res.emplace_back();      // 生成新的一层
            int qSize = q.size();    // 记录当前层的结点个数

            // 取出当前层结点
            while (qSize--) {     
                auto cur = q.front();
                q.pop();

                res.back().push_back(cur->val);

                // 把下一层结点放到队列
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }

        return res;
    }
};
// @lc code=end

// 使用双List
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> cur;
        vector<TreeNode*> next;
        vector<vector<int>> res;

        if (root) {
            cur.push_back(root);
        }

        while (!cur.empty()) {
            next.clear();
            res.emplace_back();

            for (auto c : cur) {
                res.back().push_back(c->val);
                if (c->left) next.push_back(c->left);
                if (c->right) next.push_back(c->right);
            }

            cur.swap(next);
        }

        return res;
    }
};

