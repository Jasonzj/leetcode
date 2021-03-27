/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        nums.insert(nums.begin(), 0);
        
        for (int i = 2; i < nums.size(); i++) {
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        }
        
        return nums.back();
    }
};
// @lc code=end

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int dprev = 0;
        int prev = 0;
        
        for (auto num : nums) {
            int tmp = max(prev, dprev + num);
            dprev = prev;
            prev = tmp;
        }
        
        return prev;
    }
};
