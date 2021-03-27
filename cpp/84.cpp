/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

/*
 * 思路
 * curent index = i, i下标的值比a, b都小
 * stack = [0, a, b]
 * 对于a而言, (0, a-1], A[x]值都 >= A[i]
 * [a+1 ... i-1]，A[x]值都 >= A[i]
 * 对于b而言, [b+1 ... i-1], A[x]值都 >= A[b] 
 * [a+1 ... b-1], A[x]值都 >= [b]
 * i - a - 1 就是最大宽度
*/
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        if (n == 0) return 0;
        if (n == 1) return heights[0];

        stack<int> s;
        int area = 0;

        // 哨兵
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        s.push(0);

        for (int i = 1; i < heights.size(); i++) {
            const int x = heights[i];
            while (!s.empty() && heights[s.top()] > x) {
                int idx = s.top();
                s.pop();
                int height = heights[idx];
                int left = s.top();
                int right = i;
                int width = right - left - 1;
                area = max(area, width * height);
            }
            s.push(i);
        }

        return area;
    }
};
// @lc code=end

class Solution {
public:
    vector<int> findRigthSamll(vector<int>& V) {
        vector<int> ans(V.size());
        stack<int> s;

        for (int i = 0; i < V.size(); i++) {
            int x = V[i];
            while (!s.empty() && V[s.top()] > x) {
                ans[s.top()] = i;
                s.pop(); 
            }
            s.push(i);
        }

        while(!s.empty()) {
            ans[s.top()] = -1;
            s.pop();
        }

        return ans;
    }

    vector<int> findLeftSamll(vector<int>& V) {
        vector<int> ans(V.size());
        stack<int> s;

        for (int i = V.size() - 1; i >= 0; i--) {
            int x = V[i];
            while (!s.empty() && V[s.top()] > x) {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty()) {
            ans[s.top()] = -1;
            s.pop();
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector R = findRigthSamll(heights);
        vector L = findLeftSamll(heights);

        int N = heights.size();
        int area = 0;
        for (int i = 0; i < N; i++) {
            int x = heights[i];
            int leftPos = L[i];
            int rightPos = R[i] == -1 ? N : R[i];
            int width = (rightPos - leftPos - 1);
            int c = x * width;
            area = max(area, c);
        }

        return area;
    }
};
