/**
 * @param {string} s
 * @return {number}
 */
const romanToInt = function (s) {
    const roman = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    let sum = 0
    for (let i = 0, l = s.length; i < l; i++) {
        const curr = s.charAt(i)
        const next = s.charAt(i + 1)
        const num = roman[curr]
        if (num < roman[next]) {
            sum -= num
        } else {
            sum += num
        }
    }
    return sum
}