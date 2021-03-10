/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
private:
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

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            push(cur);
            // 当i = k - 1时可以取最大值
            if (i < k - 1) continue;
            // 对首就是区间最大值
            res.push_back(q.front());
            // 控制区间
            pop(nums[i - k + 1]);
        }

        return res;
    }
};
// @lc code=end

// 使用循环队列
class Queue {
private:
    vector<int> q;
    int used = 0;
    int head = 0;
    int tail = 0;

public:
    Queue(int mod) : q(mod) {}

    int backIndex() {
        return (tail - 1 + q.size()) % q.size();
    }

    int front() {
        return q[head];
    }

    void push(int value) {
        while(used > 0 && q[backIndex()] < value) {
            tail = backIndex();
            used--;
        }

        q[tail] = value;
        tail = (tail + 1) % q.size();
        used++;
    }

    void pop(int value) {
        if (used > 0 && front() == value) {
            head = (head + 1) % q.size();
            used--;
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Queue q(k);
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);

            if (i < k - 1) continue;

            res.push_back(q.front());
            q.pop(nums[i - k + 1]);
        }

        return res;
    }
};
