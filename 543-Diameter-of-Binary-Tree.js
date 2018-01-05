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
const diameterOfBinaryTree = function(root) {
    if (!root) return 0
    let res = 1
    const preOrder = function(node) {
        if (!node) return 0
        const L = preOrder(node.left)
        const R = preOrder(node.right)
        res = Math.max(res, L + R + 1)
        return Math.max(L, R) + 1
    }
    preOrder(root)
    return res - 1
}

const t = {
    val: 1,
    left: {
        val: 2,
        left: {
            val: 4,
            left: null,
            right: null
        },
        right: {
            val: 5,
            left: null,
            right: null
        }
    },
    right: {
        val: 3,
        left: {
            val: 4,
            left: null,
            right: null
        },
        right: {
            val: 5,
            left: null,
            right: null
        }
    }
}

console.log(diameterOfBinaryTree(t))