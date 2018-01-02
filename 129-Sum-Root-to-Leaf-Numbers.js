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
const sumNumbers = function (root) {
    if (!root) return 0
    const sum = function (node, s) {
        if (!node) return 0
        if (!node.left && !node.right) return s * 10 + node.val
        return sum(node.left, s * 10 + node.val) + sum(node.right, s * 10 + node.val)
    }
    return sum(root, 0)
}

const t = {
    val: 1,
    left: { val: 2, left: null, right: null },
    right: { val: 3, left: null, right: null },
}

console.log(sumNumbers(t))