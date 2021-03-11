/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;

        for (auto v : nums) {
            int index = abs(v) - 1;
            if (nums[index] > 0) {
                nums[index] *= -1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};
// @lc code=end

