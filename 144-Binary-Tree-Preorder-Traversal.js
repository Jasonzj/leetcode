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
const preorderTraversal = function(root) {
    if (!root) return []
    const stack = [root]
    const result = []
    while (stack.length) {
        const node = stack.pop()
        result.push(node.val)
        node.right && stack.push(node.right)
        node.left && stack.push(node.left)
    }
    return result
}