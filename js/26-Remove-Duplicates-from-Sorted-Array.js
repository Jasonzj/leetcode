/**
 * @param {number[]} nums
 * @return {number}
 */
const removeDuplicates = function (nums) {
    let id = 0
    for (let i = 1; i < nums.length; i++) {
        const item = nums[i]
        if (item != nums[id]) {
            nums[++id] = item
        }
    }
    return ++id
}