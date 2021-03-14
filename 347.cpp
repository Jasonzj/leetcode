/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// 思路: 小堆
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        using pii = std::pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> h;
        
        for (auto cur : nums) ++m[cur];
        
        for (auto& cur: m) {
            h.emplace(cur.second, cur.first);
            if (h.size() > k) h.pop();
        }
        
        while (!h.empty()) {
            res.push_back(h.top().second);
            h.pop();
        }
        
        return res;
    }
};
// @lc code=end

