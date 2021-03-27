/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
class Solution {
private:
    // 单调队列
    deque<int> q;
public:
    void push(int value) {
        while (!q.empty() && q.back() < value) {
            q.pop_back();
        }
        q.push_back(value);
    }

    void pop(int value) {
        if (!q.empty() && q.front() == value) {
            q.pop_front();
        }
    }

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        // 每个位置能获得的金币数量
        vector<int> get(n);

        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            // 求最大值前，保持队列区间为k
            if (i > k) pop(get[i - k - 1]);

            int max = q.empty() ? 0 : q.front();
            get[i] = max + cur;
            
            push(get[i]);
        }

        return get[n - 1];
    }
};
// @lc code=end

class Solution {
private: 
    deque<pair<int, int>> q;
public:
    void push(int value, int index) {
        while (!q.empty() && q.back().first < value) {
            q.pop_back();
        }
        q.emplace_back(value, index);
    }

    void pop(int i, int k) {
        if (!q.empty() && i - q.front().second > k) {
            q.pop_front();
        }
    }

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            pop(i, k);

            int max = q.empty() ? 0 : q.front().first;
            res = max + cur;

            push(res, i);
        }

        return res;
    }
};

