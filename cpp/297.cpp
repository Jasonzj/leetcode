/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
 // BFS
class Codec {
    vector<string> split(string s, char sep) {
        vector<string> result;
        string tmp = "";
        for (auto c : s) {
            if (c == sep) {
                result.push_back(tmp);
                tmp = "";
            } else {
                tmp += c;
            }
        }
        
        return result;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        string res = "";
        
        while (!q.empty()) {
            int qSize = q.size();
            
            while (qSize--) {
                auto node = q.front();
                q.pop();
                
                if (node) {
                    res += to_string(node->val) + ",";
                    
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    res += "x,";
                }
            }
        }

        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() < 1) return nullptr;

        vector<string> list = split(data, ',');    // 分割字符串
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(list[0]));
        q.push(root);
        int count = 1;

        while (count < list.size()) {
            TreeNode* cur = q.front();          // 取出当前父节点
            q.pop();
            
            string leftVal = list[count];       // 取左结点的值 
            string rightVal = list[count + 1];  // 取右结点的值
                
            if (leftVal != "x") {
                TreeNode* leftNode = new TreeNode(stoi(leftVal));
                cur->left = leftNode;
                q.push(leftNode);       // 左结点进队, 因为还要取儿子
            }
            if (rightVal != "x") {
                TreeNode* rightNode = new TreeNode(stoi(rightVal));
                cur->right = rightNode;
                q.push(rightNode);      // 右结点进队, 因为还要取儿子
            }
            
            count += 2;   // 每次分配一个结点的儿子
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

