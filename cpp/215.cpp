/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> h;
        
        for (auto num : nums) {
            h.push(num);

            if (h.size() > k) {
                h.pop();
            }
        }
        
        return h.top();
    }
};
// @lc code=end

class Solution {
    int kth(vector<int> &nums, int start, int end, int k) {
        if (start >= end) return 0;
        if (start + 1 >= end) return nums[start];
        
        int mid = start + ((end - start) >> 1);
        int x = nums[mid];
        int l = start, i = start, r = end - 1;
        
        while (i <= r) {
            // 找第k大，降序
            if (nums[i] > x) {
                swap(nums[l++], nums[i++]);
            } else if (nums[i] == x) {
                i++;
            } else {
                swap(nums[r--], nums[i]);
            }
        }
        
        // 分别拿到三段的长度
        int lcnt = l - start;
        int mcnt = i - l;
        // 如果第k个数落在左区间
        if (k < lcnt)
             return kth(nums, start, l, k);
        // 如果第k个数落在右区间
        if (k >= (lcnt + mcnt))
         return kth(nums, i, end, k - lcnt - mcnt);
        // 如果第k个数落在中间，那么直接返回x
        return x;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return kth(nums, 0, nums.size(), k - 1);
    }
};

class Solution {
    void kth(vector<int> &nums, int start, int end, int k) {
        if (start >= end || start + 1 >= end) return;
        
        int mid = start + ((end - start) >> 1);
        int x = nums[mid];
        int l = start, i = start, r = end - 1;
        
        while (i <= r) {
            if (nums[i] > x) {
                swap(nums[l++], nums[i++]);
            } else if (nums[i] == x) {
                i++;
            } else {
                swap(nums[r--], nums[i]);
            }
        }
        
        // 分别拿到三段的长度
        int lcnt = l - start;
        int mcnt = i - l;
        // 如果第k个数落在左区间
        if (k < lcnt) kth(nums, start, l, k);
        // 如果第k个数落在右区间
        if (k >= (lcnt + mcnt)) kth(nums, i, end, k - lcnt - mcnt);
        // 如果第k个数落在中间，那么直接返回
        return;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        kth(nums, 0, nums.size(), k - 1);
        return nums[k - 1];
    }
};