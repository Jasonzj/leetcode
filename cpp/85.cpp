/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
    int largestRectangleArea(vector<int> &_heights) {
        vector<int> heights(_heights);
        int n = heights.size();
        
        if (n == 0) return 0;
        if (n == 1) return heights[0];
        
        stack<int> s;
        int area = 0;
        
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        s.push(0);
        
        for (int i = 1; i < heights.size(); i++) {
            int cur = heights[i];
            
            while (!s.empty() && heights[s.top()] > cur) {
                int index = s.top();
                s.pop();

                int height = heights[index];
                int left = s.top();
                int right = i;
                int width = right - left - 1;
                area = max(area, width * height);
            }
            s.push(i);
        }
        
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int res = 0;
        vector<int> heights(matrix[0].size());
        
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[0].size(); x++) {
                // 构造每一层的高度数组, 利用柱状图中最大的矩形求解
                if (matrix[y][x] == '1') {
                    heights[x] = heights[x] + 1;  
                } else {
                    heights[x] = 0;
                }
            }       
            res = max(res, largestRectangleArea(heights));
        }

        return res;
    }
};
// @lc code=end

