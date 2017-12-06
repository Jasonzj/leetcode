/**
 * @param {string} s
 * @return {string}
 */
const reverseString = function (s) {
    if (!s.length) return s
    let result = ''
    for (let i = s.length - 1; i >= 0; i--) {
        result += s[i]
    }
    return result
}