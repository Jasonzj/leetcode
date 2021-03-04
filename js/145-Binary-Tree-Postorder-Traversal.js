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
const postorderTraversal = function(root) {
    if (!root) return []
    const result = []
    const postOrder = function(node) {
        node.left && postOrder(node.left)
        node.right && postOrder(node.right)
        result.push(node.val)
    }
    postOrder(root)
    return result
}