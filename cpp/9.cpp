/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数 
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int num = x;
        long res = 0;
        
        while (num != 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        
        return x == (int)res;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string tmp = to_string(x);
        int p1 = 0, p2 = tmp.size() - 1;
        
        while (p1 < p2) {
            if (tmp[p1++] != tmp[p2--]) return false;
        }
        
        return true;
    }
};