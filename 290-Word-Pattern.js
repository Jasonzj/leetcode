/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
const wordPattern = function (pattern, str) {
    const map = {}
    const map2 = {}
    const strs = str.split(' ')
    if (pattern.length !== strs.length) return false
    for (let i = 0, l = pattern.length; i < l; i++) {
        const p = pattern[i]
        const s = strs[i]
        if (map[p]) {
            if (map[p] !== s) return false
        } else {
            map[p] = s
        }
        if (map2[s]) {
            if (map2[s] !== p) return false
        } else {
            map2[s] = p
        }
    }
    return true
}