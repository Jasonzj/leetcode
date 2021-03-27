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
        unordered_map<int, int> m;  // 记录频率
        using pii = std::pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> h;   // 小堆
        
        for (auto cur : nums) ++m[cur];
        
        for (auto& cur: m) {
            h.emplace(cur.second, cur.first);
            // 堆中元素数量大于K时，把堆头最小频率弹出，堆中始终保持当前频率最高的k个数
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

