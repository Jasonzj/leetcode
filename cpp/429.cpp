/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;        
        vector<vector<int>> res;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int qSize = q.size();
            res.emplace_back();

            while (qSize--) {
                auto cur = q.front();
                q.pop();
                res.back().push_back(cur->val);

                for (auto child : cur->children) {
                    q.push(child);
                }
            }
        }

        return res;
    }
};
// @lc code=end

