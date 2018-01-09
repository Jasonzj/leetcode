/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
const maxDepth = function (root) {
    let res = 0
    if (!root) return res
    const postOrder = function (node, depth) {
        if (!node) return
        node.left && postOrder(node.left, depth + 1)
        node.right && postOrder(node.right, depth + 1)
        if (!node.left && !node.right) res = Math.max(res, depth)
    }
    postOrder(root, 0)
    return res + 1
}

/* ----------------------------------------------------------------- */

const maxDepth = function (root) {
    if (!root) return 0
    else return max( maxDepth(root.left), maxDepth(root.right) ) + 1
}

function max(a, b) {
    return a > b ? a : b
}

const t = {
    val: 3,
    left: {
        val: 4,
        left: { val: 1, left: null, right: null },
        right: { val: 2, left: null, right: null }
    },
    right: { val: 5, left: null, right: null }
}

console.log(maxDepth(t))