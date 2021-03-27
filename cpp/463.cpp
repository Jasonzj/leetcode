/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
    bool isArea(vector<vector<int>>& grid, int y, int x) {
        return y >= 0 && y < grid.size()
            && x >= 0 && x < grid[0].size();
    }
    
    int dfs(vector<vector<int>>& grid, int y, int x) {
        if (!isArea(grid, y, x)) return 1; // 碰到边界, 是岛屿的边 
        if (grid[y][x] == 0) return 1;     // 碰到海洋, 是岛屿的边 
        if (grid[y][x] == 2) return 0;     // 遍历过
        
        grid[y][x] = 2;
        
        return dfs(grid, y - 1, x)
            + dfs(grid, y + 1, x)
            + dfs(grid, y, x - 1)
            + dfs(grid, y, x + 1);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 1) {
                    return dfs(grid, y, x);
                }
            }
        }
        
        return 0;
    }
};
// @lc code=end

