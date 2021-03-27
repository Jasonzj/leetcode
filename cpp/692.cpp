/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;
        using pii = std::pair<int, string>;
        
        auto cmp = [](pii& a, pii& b) {
            if (a.first != b.first) {
                return b.first < a.first;
            }
            // 频率一样，按字母顺序
            return b.second > a.second;
        };
        
        priority_queue<pii, vector<pii>, decltype(cmp)> h(cmp); // 小堆
    
        for (auto cur : words) ++m[cur];
        
        for (auto& cur : m) {
            h.emplace(cur.second, cur.first);
            if (h.size() > k) {
                h.pop();
            }
        }
        
        while (!h.empty()) {
            res.push_back(h.top().second);
            h.pop();
        }
        
        // 频率从高到低
        reverse(res.begin(), res.end());
        
        return res;
    }
};
// @lc code=end

