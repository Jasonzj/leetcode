/**
 * @param {number} n - a positive integer
 * @return {number}
 */
const hammingWeight = function(n) {
    let res = 0
    while (n != 0) {
        n &= n - 1
        res++
    }
    return res
}

const hammingWeight = function(n) {
    return n.toString(2).replace(/0/g, '').length
}