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
const rightSideView = function(root) {
    const result = []
    const preOrder = function(node, depth) {
        if (!node) return
        if (result.length === depth) result.push(node.val)
        preOrder(node.right, depth + 1)
        preOrder(node.left, depth + 1)
    }
    
    preOrder(root, 0)
    
    return result
}

const t = {
    val: 3,
    left: {
        val: 4,
        left: { val: 1, left: null, right: null },
        right: { val: 2, left: null, right: null }
    },
    right: {
        val: 5, left: null, right: null }
}

rightSideView(t)    // [3, 5, 2]