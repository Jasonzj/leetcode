/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

class Solution {
    void swap(vector<int> &A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int l = 0, i = 0, r = len - 1;
        
        while (i <= r) {
            int cur = nums[i];
            if (cur == 0) {
                swap(nums, l++, i++);
            } else if (cur == 1) {
                i++;
            } else {
                swap(nums, r--, i);
            }
        }
    }
};