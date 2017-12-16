/**
 * @param {string} str
 * @returns {string}
 */
const reverseWords = function (str) {
    const arr = str.trim().split(' ')
    let result = ''
    for (let l = arr.length - 1; l >= 0; l--) {
        const s = arr[l]
        if (s) {
            result += `${arr[l]}${l > 0 ? ' ' : ''}`
        }
    }
    return result
}

const reverseWords = function (str) {
    return str.split(' ').reverse().filter(s => s).join(' ')
}