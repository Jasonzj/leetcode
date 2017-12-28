/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
const averageOfLevels = function(root) {
    const result = []
    if (!root) return result
    const preOrder = function(node, depth) {
        if (!node) return
        result[depth] ? result[depth].push(node.val) : result[depth] = [node.val]
        node.left && preOrder(node.left, depth + 1)
        node.right && preOrder(node.right, depth + 1)
    }
    preOrder(root, 0)
    return result.map(arr => arr.reduce((a, b) => a + b, 0) / arr.length)
}

/* ---------------------------------------------------------------------------------- */

const averageOfLevels = function (root) {
    const result = []
    const queue = [root]
    if (!root) return result
    while (queue.length) {
        let n = queue.length
        let sum = 0
        for (let i = 0; i < n; i++) {
            const node = queue.shift()
            sum += node.val
            node.left && queue.push(node.left)
            node.right && queue.push(node.right)
        }
        result.push(sum / n)
    }
    return result
}