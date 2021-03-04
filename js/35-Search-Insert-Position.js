/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const searchInsert = function (nums, target) {
    for (let i = 0, l = nums.length; i < l; i++) {
        const item = nums[i]
        if (item >= target) {
            return i
        }
    }
    return nums.length
}