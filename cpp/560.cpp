/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为k的子数组 
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;  // 前缀和map
        int res = 0;
        int sum = 0;
        // 处理路径包括首元素的情况
        m[0] = 1;
        
        for (auto n : nums) {
            sum += n;
            if (m[sum - k]) res += m[sum - k];
            m[sum]++;
        }
        
        return res;
    }
};