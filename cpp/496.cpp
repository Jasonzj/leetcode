/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        vector<int> ans(n1, -1);
        unordered_map<int, int> u;
        stack<int> s;

        for (int i = 0; i < nums2.size(); i++) {
            int x = nums2[i];
            while (!s.empty() && x > nums2[s.top()]) {
                u[nums2[s.top()]] = x;
                s.pop();
            }
            s.push(i);
        }

        for (int i = 0; i < n1; i++) {
            int x = nums1[i];
            if (u[x]) ans[i] = u[x];
        }

        return ans;
    }
};
// @lc code=end

