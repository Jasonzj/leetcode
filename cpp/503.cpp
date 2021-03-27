/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n * 2 - 1; i++) {
            int x = nums[i % n];
            while (!s.empty() && x > nums[s.top()]) {
                ans[s.top()] = x;
                s.pop();
            }
            s.push(i % n);
        }
        
        return ans;
    }
};
// @lc code=end

