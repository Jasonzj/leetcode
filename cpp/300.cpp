/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        
        vector<int> v;
        v.push_back(nums[0]);
        int end = 0;
        
        for (int i = 1; i < len; i++) {
            // 严格大于 v 数组最后一个元素, 直接添加到后面
            if (v[end] < nums[i]) {
                end++;
                v.push_back(nums[i]);
            } else {
                // num[i] <= v[end], 找到 v 第一个 >= nums[i] 的替换
                int l = 0, r = end;
                while (l < r) {
                    int m = l + ((r - l) >> 1);
                    if (v[m] < nums[i]) {
                        // 丢掉左边 [l, m]
                        // [m + 1, r)
                        l = m + 1;
                    } else {
                        // 丢右边[m, r)
                        // [l, m)
                        r = m;
                    }
                }
                v[l] = nums[i];
            }
        }
        
        return end + 1;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        
        vector<int> dp(len, 1);
        int res = 0;
        
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);   
                }
            }
        }
        
        for (auto n : dp) {
            res = max(res, n);
        }
        
        return res;
    }
};