/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
    bool isArea(vector<vector<char>>& grid, int y, int x) {
        return y >= 0 && y < grid.size()
            && x >= 0 && x < grid[0].size();
    }
    
    void dfs(vector<vector<char>>& grid, int y, int x) {
        if (!isArea(grid, y, x)) return; 
        if (grid[y][x] != '1') return;   // 当前是海洋或者已遍历过
        
        grid[y][x] = '2';  // 标记为已遍历过
        
        dfs(grid, y - 1, x);
        dfs(grid, y + 1, x);
        dfs(grid, y, x - 1);
        dfs(grid, y, x + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == '1') {  // 把当前岛屿用dfs全部标记为2, 下次走的就是下个岛屿了
                    dfs(grid, y, x);
                    res++;
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

