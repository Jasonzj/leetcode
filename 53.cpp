/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        for (auto cur : nums) {
            sum += cur;
            res = max(res, sum);
            if (sum < 0) {
                sum = 0;
            }
        }

        return sum;
    }
};
// @lc code=end

