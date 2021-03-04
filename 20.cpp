/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        stack<char> t;
        for (char c: s) {
            if (c == '{' || c == '(' || c == '[') {
                t.push(c);
            } else if (c == ')') {
                if (t.empty() || t.top() != '(') {
                    return false;
                }
                t.pop();
            } else if (c == '}') {
                if (t.empty() || t.top() != '[') {
                    return false;
                }
                t.pop();
            } else if (c == ']') {
                if (t.empty() || t.top() != '[') {
                    return false;
                }
                t.pop();
            } else {
                return false;
            }
        }

        return t.empty()
    }
};
// @lc code=end
