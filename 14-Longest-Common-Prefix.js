/**
 * @param {string[]} strs
 * @return {string}
 */
const longestCommonPrefix = function (strs) {
    if (!strs.length || !strs instanceof Array) {
        return ''
    }
    let result = ''
    const curr = strs[0]
    for (let i = 0; i < curr.length; i++) {
        const diff = curr[i]
        if (strs.every(item => item[i] === diff)) {
            result += diff
        } else {
            return result
        }
    }
    return result
}