/**
 * @param {number[]} nums
 * @return {number}
 */
const findMaxConsecutiveOnes = function (nums) {
    let result = 0
    let cur = 0
    for (let i = 0, l = nums.length; i < l; i++) {
        const num = nums[i]
        if (num === 1) {
            cur++
            result = Math.max(cur, result)
        } else cur = 0
    }
    return result
}