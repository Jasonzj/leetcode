/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
    const map = {}
    for (let i = 0, l = numbers.length; i < l; i++) {
        const num = numbers[i]
        const diff = map[target - num]
        if (diff !== undefined) {
            return [diff + 1, i + 1]
        }
        map[num] = i
    }
    return []
}