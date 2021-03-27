/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> st; // 递减桟

        if (T.size() == 1) return {0};

        for (int i = 0; i < n; i++) {
            // 桟不为空且当前值大于桟顶值则消除栈顶值
            while (!st.empty() && T[i] > T[st.top()]) { 
                int prevIndex = st.top();
                ans[prevIndex] = i - prevIndex;
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
// @lc code=end

