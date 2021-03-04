/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
const invertTree = function (root) {
    if (root) {
        const { right, left } = root
        root.left = invertTree(right)
        root.right = invertTree(left)
        // const m = node.left
        // node.left = node.right
        // node.right = m
        // treeRollover(node.left)
        // treeRollover(node.right)
    }
    return root
}