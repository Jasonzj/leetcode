/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t x) {
        int res = 0;
        while (x) {
            x &= x - 1;
            res++;
        }
        return res;
    }
};
// @lc code=end

