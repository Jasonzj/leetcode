/**
 * @param {number} n
 * @return {string[]}
 */
const fizzBuzz = function (n) {
    const result = []
    let i = 1;
    let str

    while (i <= n) {
        str = ""
        if (i % 3 === 0) str = 'Fizz'
        if (i % 5 === 0) str += 'Buzz'
        if (!str) str += i
        result.push(str)
        i++
    }

    return result
}
