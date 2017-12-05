/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const moveZeroes = function (nums) {
    let j = 0
    for (let i = 0, l = nums.length; i < l; i++) {
        if (nums[i] !== 0) {
            let temp = nums[j]
            nums[j] = nums[i]
            nums[i] = temp
            j++
        }
    }
}