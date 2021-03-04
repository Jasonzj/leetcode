/**
 * @param {number} x
 * @return {number}
 */
const reverse = function (x) {
    const arr = parseInt(x.toString().split('').reverse().join(''))
    if (arr > 2147483647 || arr < -2147483648) return 0
    return Number(x) > 0 ? arr : -arr
}