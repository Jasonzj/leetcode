/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

class Solution {
    int lowerBound(vector<int> &nums, int target, int len) {
        int l = 0, r = len;
        
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        return l;
    }
    
    int upperBound(vector<int> &nums, int target, int len) {
        int l = 0, r = len;
        
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        return l;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0 || nums[len - 1] < target) return {-1, -1};
        int l = lowerBound(nums, target, len);
        int r = upperBound(nums, target, len);
        
        if (nums[l] != target) return {-1, -1};
            
        return {l, r - 1};
    }
};