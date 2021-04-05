/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入元素
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        if (nums[len - 1] < target) return len;
        
        int l = 0, r = len;
        
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] < target) {
                // 丢掉左边 [l, m]
                // [m + 1, r)
                l = m + 1;
            } else {
                // 丢右边[m, r)
                // [l, m)
                r = m;
            }
        }
        
        return l;
    }
};