/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> h;
        
        for (int i = 0; i < nums.size(); i++) {
            h.push(nums[i]);
        }
        
        for (int i = 0; i < k - 1; i++) {
            h.pop();
        }
        
        return h.top();
    }
};
// @lc code=end

