/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> s;
        int area = 0;
        
        for (int i = 0; i < n; i++) {
            int x = height[i];
            while (!s.empty() && height[s.top()] < x) {
                int idx = s.top();
                s.pop();
                if (s.empty()) break;
                int left = s.top();
                int right = i;
                int w = right - left - 1;
                int h = min(height[left], height[right]) - height[idx];
                area += w * h; 
            }
            s.push(i);
        }

        return area;
    }
};
// @lc code=end

