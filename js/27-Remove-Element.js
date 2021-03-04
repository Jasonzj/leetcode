/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
const removeElement = function (nums, val) {
    for (let i = nums.length - 1; i >= 0; i--) {
        if (nums[i] === val) nums.splice(i, 1)
    }
};

// var removeElement = function(nums, val) {
//     let i = 0
//     let n = nums.length
//     while (i < n) {
//         if (nums[i] === val) {
//             nums[i] = nums[--n]
//         } else {
//             i++
//         }
//     }
//     nums.length = i
// }