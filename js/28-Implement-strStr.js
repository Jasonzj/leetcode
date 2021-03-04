/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
const strStr = function (haystack, needle) {
    const hLen = haystack.length
    const nLen = needle.length
    if (!nLen) return 0
    for (let i = 0; i < hLen - nLen + 1; i++) {
        let j = 0
        for (; j < nLen; j++) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == nLen) return i
    }
    return -1
}