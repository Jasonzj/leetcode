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
const findTilt = function(root) {
    let tilt = 0
    if (!root) return tilt
    const postOrder = function(node) {
        const left = node.left ? postOrder(node.left) : 0
        const right = node.right ? postOrder(node.right) : 0
        tilt += Math.abs(left - right)
        return node.val + left + right
    }
    postOrder(root, 0)
    return tilt
}

const t = {
    val: 1,
    left: { val: 2, left: { val: 4, left: null, right: null }, right: null },
    right: { val: 3, left: { val: 5, left: null, right: null }, right: null }
}

findTilt(t)