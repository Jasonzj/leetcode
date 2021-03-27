/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [1642] 可以到达的最远建筑
 */

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if (heights.empty()) {
            return -1;
        }
        
        int res = 0;
        int prevHeight = heights[0];
        int diffSum = 0;        // 高度差总和 
        priority_queue<int> H;  // 大堆，用来记录高度差
        
        for (int i = 1; i < heights.size(); i++) {
            int curHeight = heights[i];
            // 如果是高向低挑
            if (curHeight < prevHeight) {
                res = i;
            } else {
                int diff = curHeight - prevHeight;
                H.push(diff);
                diffSum += diff;
                
                // 如果高度差总和大于bricks, 则使用梯子
                while (diffSum > bricks && ladders > 0) {
                    diffSum -= H.top();
                    H.pop();
                    ladders--;
                }
                
                // 如果高度差小于bricks，可以跳到i
                if (diffSum <= bricks) {
                    res = i;
                } else {
                    // 跳不到i, 跳出循环
                    break;
                }
                
            }
            
            prevHeight = curHeight;
        }
        
        return res;
    }
};