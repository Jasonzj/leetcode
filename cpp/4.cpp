/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int len1 = nums1.size();
        int len2 = nums2.size();
        int p1 = 0;
        int p2 = 0;

        // 要扔掉的个数
        int k = (len - 1) >> 1;

        while (k > 0) {
            // 取要扔掉个数的中间
            int mid = (k - 1) >> 1;

            // 比较大小选择要丢掉得子数组的mid个
            if (p2 + mid >= len2 || (p1 + mid < len1 && nums1[p1 + mid] < nums2[p2 + mid])) {
                p1 += mid + 1;
            } else {
                p2 += mid + 1;
            }

            k -= mid + 1;
        }

        double front = (p2 >= len2 || p1 < len1 && nums1[p1] < nums2[p2]) ? nums1[p1++] : nums2[p2++];

        if (len & 1) return front;

        double back = (p2 >= len2 || p1 < len1 && nums1[p1] < nums2[p2]) ? nums1[p1] : nums2[p2];

        return (front + back) / 2.0;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        nums1.resize(m + n);
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
        
        while (n >= 0) {
            nums1[p--] = nums2[n--];
        }
        
        int len = nums1.size();
        if (len & 1) {
            return nums1[len / 2];
        } else {
            return (nums1[len / 2 - 1] + nums1[len / 2]) / 2.0;
        }
    }
};