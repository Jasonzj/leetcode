/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int p1 = 0, p2 = s.size() - 1;
        if (p2 < 1) return;
        
        while (p1 < p2) {
            swap(s[p1++], s[p2--]);
        }
    }
};