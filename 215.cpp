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

