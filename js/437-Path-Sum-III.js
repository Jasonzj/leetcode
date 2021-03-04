/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number}
 */
const pathSum = function (root, sum) {
    if (!root) return 0
    let result = 0
    function dfs(root, sofar, cache) {
        if (!root) return
        let curSum = sofar + root.val
        let target = curSum - sum
        console.warn(`sofar: ${sofar}, val: ${root.val}`)
        console.warn(`curSum: ${curSum}`)
        console.warn(`target: ${target}`)
        if (cache[target]) {
            result += cache[target]
        }
        cache[curSum] = (cache[curSum] || 0) + 1
        console.log(cache)
        dfs(root.left, curSum, cache)
        dfs(root.right, curSum, cache)
        cache[curSum]--
    }
    dfs(root, 0, { 0: 1 })
    return result
}

const pathSum = function (root, sum) {
    if (!root) return 0

    const searchSum = function (root, sum) {
        if (!root) return 0
        return (root.val == sum ? 1 : 0) + searchSum(root.left, sum - root.val) + searchSum(root.right, sum - root.val)
    }

    return searchSum(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum)
}