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
const inorderTraversal = function (root) {
    if (!root) return []
    const result = []
    const inOrder = function (node) {
        if (!node) return
        node.left && inOrder(node.left)
        result.push(node.val)
        node.right && inOrder(node.right)
    }
    inOrder(root)
    return result
}