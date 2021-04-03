/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
// 归并排序
class Solution {
    void merge(vector<int> &nums, int start, int end, vector<int> &tmp) {
        // 处理空区间，和只有一个元素的区间
        if (start >= end || start + 1 >= end) return;

        // 取区间中值
        int mid = start + ((end - start) >> 1);

        merge(nums, start, mid, tmp);
        merge(nums, mid, end, tmp);

        int p1 = start;  // 左数组开头
        int p2 = mid;    // 右数组开头
        int to = start;  // 临时数组尾指针

        while (p1 < mid || p2 < end) {
            // 如果右子数组没有元素 或 左子数组开头的元素小于右子数组开头的元素
            if (p2 >= end || p1 < mid && nums[p1] <= nums[p2]) {
                tmp[to++] = nums[p1++];
            } else {
                tmp[to++] = nums[p2++];
            }
        }

        // 合并结果给到nums
        for (int i = start; i < end; i++) {
            nums[i] = tmp[i];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return nums;

        vector<int> tmp(nums.size());
        merge(nums, 0, nums.size(), tmp);
        return nums;
    }
};
// @lc code=end

class Solution {
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void qSort(vector<int> &nums, int start, int end) {
        if (start >= end || start + 1 >= end) return;
        
        int mid = start + ((end - start) >> 1);
        int x = nums[mid];
        
        int l = start, i = start, r = end - 1;
        
        while (i <= r) {
            if (nums[i] < x) {
                swap(nums, l++, i++);
            } else if (nums[i] == x) {
                i++;
            } else {
                swap(nums, r--, i);
            }
        }
        
        qSort(nums, start, l);
        qSort(nums, i, end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return nums;
        
        qSort(nums, 0, nums.size());
        
        return nums;
    }
};

