/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int count = 0;
        // 每次消除最后一个1
        while (x) {
            x &= x - 1;
            count++;
        }
        return count;
    }
};
// @lc code=end

