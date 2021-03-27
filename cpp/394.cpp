/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<string> strs;
        stack<int> nums;
        string res = "";
        int num = 0;

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '[') {  // 把当前记录字符res和num入栈, 并清空res和num
                nums.push(num);
                strs.push(res);
                res.clear();
                num = 0;
            } else if (c == ']' ) { 
                int times = nums.top();
                nums.pop();
                // res = lastStr + num * curStr(括号里的字符)
                for (int i = 0; i < times; i++) {
                    strs.top() += res;   
                }
                res = strs.top();
                strs.pop();
            } else {
                res += c;
            }
        } 
        return res;
    }
};
// @lc code=end

class Solution {
public:
    string analysis(string s, int& index) {
        string res;
        int num = 0;
        string temp;
        while (index < s.size()) {
            int c = s[index];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            else if (c == '[') {
                temp = analysis(s, ++index);
                for (int i = 0; i < num; i++) {
                    res += temp;
                }
                num = 0;
            }
            else if (c == ']') {
                break;
            } 
            else {
                res += c;
            }
            index++;
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return analysis(s, index);
    }
};