/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isAnagram = function(s, t) {
    if (!s && !t) return true
    if (s.length != t.length) return false
    const alphabet = new Array(26).fill(0)
    const _a = 'a'.charCodeAt(0)
    for (let i = s.length - 1; i >= 0; i--) {
        alphabet[s[i].charCodeAt(0) - _a]++
    }
    for (let i = t.length - 1; i >= 0; i--) {
        alphabet[t[i].charCodeAt(0) - _a]--
    }
    for (let i = alphabet.length - 1; i >=0; i--) {
        if (alphabet[i] !== 0) return false
    }
    return true
}