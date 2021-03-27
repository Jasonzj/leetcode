/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;
        m--;
        n--;
        
        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[p--] = nums1[m--];
            } else {
                nums1[p--] = nums2[n--];
            }
        }
        
        // 处理数组2没对比完的情况 
        while (n >= 0) {
            nums1[p--] = nums2[n--];
        }
    }
};
// @lc code=end

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int p1 = 0;
        int p2 = 0;
        
        while (p1 < m && p2 < n) {
            if (nums1[p1] < nums2[p2]) {
                result.push_back(nums1[p1]);
                p1++;
            } else {
                result.push_back(nums2[p2]);
                p2++;
            }
        }
        
        
        if (p2 < n) {
            for (; p2 < n; p2++) {
                result.push_back(nums2[p2]);
            }
        }
        if (p1  < m) {
            for (; p1 < m; p1++) {
                result.push_back(nums1[p1]);
            }
        }
        
        nums1 = result;
    }
};
