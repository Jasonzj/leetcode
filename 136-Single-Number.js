/**
 * @param {number[]} nums
 * @return {number}
 */
const singleNumber = function (nums) {
    let ans = 0
    for (let i = 0, l = nums.length; i < l; i++) {
        ans ^= nums[i]
    }
    return ans
}