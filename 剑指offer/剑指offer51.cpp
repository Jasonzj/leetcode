class Solution {
    void merge(vector<int> &nums, int start, int end, vector<int> &tmp, int &res) {
        if (start >= end || start + 1 >= end) return;
        
        int mid = start + ((end - start) >> 1);
        
        merge(nums, start, mid, tmp, res);
        merge(nums, mid, end, tmp, res);
        
        int p1 = start;
        int p2 = mid;
        int to = start;
        
        while (p1 < mid || p2 < end) {
            if (p2 >= end || p1 < mid && nums[p1] <= nums[p2]) {
                tmp[to++] = nums[p1++];
            } else {
                tmp[to++] = nums[p2++];
                res += mid - p1;
            }
        }
        
        for (int i = start; i < end; i++) {
            nums[i] = tmp[i];
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return 0;
        
        int res = 0;
        vector<int> tmp(nums.size());
        
        merge(nums, 0, nums.size(), tmp, res);
        
        return res;
    }
};