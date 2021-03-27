/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) {
            q.push(root);
        } 

        while (!q.empty()) {
            int qSize = q.size();  // 记录当前层的结点个数，每层需要固定，queue每次都在变动

            while (qSize--) {
                auto cur = q.front();
                q.pop();
                
                if (qSize) cur->next = q.front();  // 不是当前层最后一个结点
                else cur->next = NULL;             

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }

        return root; 
    }
};
// @lc code=end

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;

        if (root) {
            q.push(root);
        } 

        while (!q.empty()) {
            int qSize = q.size();     // 记录当前层的结点个数
            Node* curNode = nullptr;
            Node* preNode = nullptr;

            for (int i = 0; i < qSize; i++) {
                // 取出当前层的头结点
                if (i == 0) {
                    preNode = q.front();
                    curNode = preNode;
                    q.pop();
                } else {
                    curNode = q.front();
                    q.pop();
                    preNode->next = curNode;
                    preNode = preNode->next;
                }

                // 把下一层结点放到队列
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
            // 当前层最后一个结点next置为NULL
            preNode->next = NULL;
        }

        return root;
    }
};
