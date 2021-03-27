/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
    bool inArea(vector<vector<int>> &grid, int y, int x) {
        return x >= 0 && x < grid[0].size() 
            && y >= 0 && y < grid.size();
    }
    
    int dfs(vector<vector<int>> &grid, int y, int x) {
        if (!inArea(grid, y, x)) return 0;
        if (grid[y][x] != 1) return 0;
        
        grid[y][x] = 2;
            
        return 1
            + dfs(grid, y - 1, x)
            + dfs(grid, y + 1, x)
            + dfs(grid, y, x - 1)
            + dfs(grid, y, x + 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 1) {
                    res = max(res, dfs(grid, y, x));
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

