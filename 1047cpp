/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (auto c : S) {
            bool isPush = true;
            while (!res.empty() && c == res.back()) {
                res.pop_back();
                isPush = false;
            }
            if (isPush) res.push_back(c);
        }
        
        return res;
    }
};
// @lc code=end

