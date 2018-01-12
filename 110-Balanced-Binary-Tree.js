/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
const isBalanced = function(root) {
    let res = true
    if (!root) return res
    const postOrder = function(node, depth) {
        const left = node.left && postOrder(node.left, depth + 1) - depth
        const right = node.right && postOrder(node.right, depth + 1) - depth
        if (Math.abs(left - right) > 1) {
            res = false
            return
        }
        return depth + Math.max(left, right)
    }
    postOrder(root, 0)
    return res
}

const t = {
    val: 1,
    left: {
        val: 2,
        left: { 
            val: 4,
            left: { val: 5, left: null, right: null },
            right: null
        },
        right: null
    },
    right: {
        val: 3, left: null, right: null
    }
}

console.log(isBalanced(t))