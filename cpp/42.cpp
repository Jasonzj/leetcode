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
        stack<int> s; // 递减桟
        int area = 0;
        
        for (int i = 0; i < n; i++) {
            int x = height[i];
            // 对比栈顶和当前值，遇到更高的就可以开始计算接水量 
            while (!s.empty() && height[s.top()] < x) {
                int idx = s.top(); // 拿到当前水坑索引
                s.pop();
                if (s.empty()) break; // 左边找不到更高的墙, 接不到水
                int left = s.top();   // 左边界 
                int right = i;        // 右边界
                int w = right - left - 1;
                int h = min(height[left], height[right]) - height[idx]; // 取两边较低的墙减去底面
                area += w * h;  // 计算当前水坑能接到的水
            }
            s.push(i);
        }

        return area;
    }
};
// @lc code=end

