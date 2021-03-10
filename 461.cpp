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
        // 移位计数
        while (x) {
            if (x & 1) count++;
            x >>= 1;
        }
        return count;
    }
};
// @lc code=end

