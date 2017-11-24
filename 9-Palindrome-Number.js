/**
 * @param {number} x
 * @return {boolean}
 */
const isPalindrome = function (x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false
    }
    let num = 0
    while (x > num) {
        num = num * 10 + x % 10
        x = (x - x % 10) / 10
    }
    return x == num || x == (num - num % 10) / 10
}
