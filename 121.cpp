/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// DP, 记录今天之前买入的最小值，计算今天和最小值的差得到今天的最大获利，比较每天最大获利取最大值
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_value = prices[0];
        int max_value = 0;

        for (auto cur : prices) {
            max_value = max(max_value, cur - min_value);
            min_value = min(min_value, cur);
        }
        
        return max_value;
    }
};
// @lc code=end

// 单调递增队列, 对首是最小值，出栈计算差值取最大
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> s;
        int max_value = 0;
        prices.push_back(0);
        
        for (int i = 0; i < prices.size(); i++) {
            int cur = prices[i];
            while (!s.empty() && s.back() > cur) {
                max_value = max(max_value, s.back() - s.front());
                s.pop_back();
            }
            s.push_back(cur);
        } 
        
        return max_value;
    }
};
