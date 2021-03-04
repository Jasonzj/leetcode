/**
 * @param {number[]} nums
 * @return {number}
 */

function swap(nums, a, b) {
    var temp = nums[a]
    nums[a] = nums[b]
    nums[b] = temp
}

function quickSort(array, start, end) {
    if (start >= end) {
        return
    }

    let pivot = array[end]
    let j = start - 1
    for (let i = start; i <= end; i++) {
        let elem = array[i]
        if (elem <= pivot) {
            j++
            swap(array, i, j)
        }
    }
    let pivotInd = j
    quickSort(array, start, pivotInd - 1)
    quickSort(array, pivotInd + 1, end)
}

var arrayPairSum = function (nums) {
    quickSort(nums, 0, nums.length - 1)
    let sum = 0

    for (let i = 0; i < nums.length; i += 2) {
        sum += nums[i]
    }
    return sum
}