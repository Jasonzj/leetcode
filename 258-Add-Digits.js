/**
 * @param {number} num
 * @return {number}
 */
const addDigits = function (num) {
    const res = num % 9
    return (res != 0 || num == 0) ? res : 9
}