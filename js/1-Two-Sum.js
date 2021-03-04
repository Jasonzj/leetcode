/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = function (arr, target) {
    const map = {}
    for (let i = 0, len = arr.length; i < len; i++) {
        const item = arr[i]
        const diff = map[target - item]
        if (diff !== undefined) {
            return [diff, i]
        }
        map[item] = i
    }
    return []
}