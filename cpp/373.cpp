/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
        if (A.empty() || B.empty() || k <= 0) {
            return {};
        }

        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return A[a.first] + B[a.second] > A[b.first] + B[b.second];  // 比较对数和
        };

        vector<vector<int>> res; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> h(cmp);   // 小堆

        for (int i = 0; i < A.size(); i++) {
            h.emplace(i, 0);
        }        

        for (int i = 0; i < k && !h.empty(); i++) {
            auto cur = h.top();
            h.pop();
            res.push_back({A[cur.first], B[cur.second]});
            if (cur.second + 1 < B.size()) {
                h.emplace(cur.first, cur.second + 1);
            }
        }

        return res;
    }
};
// @lc code=end

