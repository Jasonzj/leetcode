/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    vector<int> prices;
    stack<int> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 0;
        
        while (!s.empty() && prices[s.top()] <= price) {
            s.pop();
        }
        
        count = s.empty() ? prices.size() + 1 : prices.size() - s.top();
        s.push(prices.size());
        prices.push_back(price);
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

