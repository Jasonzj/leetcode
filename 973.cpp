/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        using pii = std::pair<int, vector<int>>;
        priority_queue<pii> h;  // 大堆
        
        for (auto& cur : points) {
            int distance = pow(cur[0], 2) + pow(cur[1], 2);
            h.emplace(distance, cur);
            // 堆中元素数量大于K时，把堆头最大距离的点弹出，堆中始终保持距离最近的的k个点
            if (h.size() > k) h.pop();
        }
        
        while(!h.empty()) {
            res.push_back(h.top().second);
            h.pop();
        }
        
        return res;
    }
};
// @lc code=end

