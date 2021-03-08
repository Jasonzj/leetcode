/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
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
    int maxDepth(Node* root) {
        queue<Node*> q;        
        int res = 0;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            auto cur = q.front();
            int qSize = q.size();
            res++;
            while (qSize--) {
                q.pop();
                for (auto child : cur->children) {
                    q.push(child);
                }
            }
        }

        return res;
    }
};
// @lc code=end

