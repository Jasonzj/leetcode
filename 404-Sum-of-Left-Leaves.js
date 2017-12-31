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
const sumOfLeftLeaves = function (root) {
    if (!root) return 0
    let result = 0
    const preOrder = function (node, isLeft) {
        if (!node) return
        if (!node.left && !node.right && isLeft) {
            result += node.val
        }
        node.left && preOrder(node.left, true)
        node.right && preOrder(node.right, false)
    }
    preOrder(root, false)
    return result
}

const t = {
    val: 3,
    left: { val: 9, left: null, right: null },
    right: { val: 20, left: { val: 15, left: null, right: null }, right: { val: 7, left: null, right: null }  }
}

console.log(sumOfLeftLeaves(t))
