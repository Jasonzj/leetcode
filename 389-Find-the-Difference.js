/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
const findTheDifference = function (s, t) {
    const arr = s.split('')
    arr.forEach(item => t = t.replace(item, ''))
    return t
}