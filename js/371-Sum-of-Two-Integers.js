/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
const getSum = function (a, b) {
    while (b) {
        var carry = a & b
        a = a ^ b
        b = carry << 1
    }
    return a
}