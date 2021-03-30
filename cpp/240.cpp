/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
// 从右上角开始折线搜索
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int y = 0;
        int x = matrix[0].size() - 1;

        while (x >= 0 && y < matrix.size()) {
            if (matrix[y][x] == target) {
                return true;
            } else if (matrix[y][x] > target) {  // 当前值大于目标往左搜
                x--;
            } else if (matrix[y][x] < target) {  // 当前值小于目标往下搜
                y++;
            }
        }
        
        return false;
    }
};

// @lc code=end

