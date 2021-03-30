/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
// 从左下角开始搜，先搜行，再搜列
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        
        int y = matrix.size() - 1;
        int x = 0;
        
        while(y >= 0 && x < matrix[0].size()) {
            if (matrix[y][x] == target) {
                return true;
            } else if (matrix[y][0] > target) {
                y--;
            } else {
                x++;
            }
        }
        
        return false;
    }
};
// @lc code=end

