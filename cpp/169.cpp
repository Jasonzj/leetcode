class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res;
        int count = 0;
        for (auto v : nums) {
            if (!count) {
                res = v;
                count++;
            }
            else {
                if (res == v) count++;
                else count--;
            }
        }
        return res;
    }
};