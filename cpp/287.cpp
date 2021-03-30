/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
// 把元素值当做指针，存在重复必然有环，通过求环入口求解
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        
        slow = nums[0];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
// @lc code=end

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = -1;
        
        for (auto n : nums) {
            if (m[n]) {
                res = n;
            } else {
                m[n] = 1;
            }
        }
        
        return res;
    }
};