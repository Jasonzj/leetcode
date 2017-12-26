/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root   particular
 * @return {string[]}
 */
const binaryTreePaths = function(root) {
    if (!root) return []
    const result = []

    const preOrder = function(node, path) {
        if (!node) return

        path += node.val

        if (!node.left && !node.right) result.push(path)
        else path += '->'

        node.left && preOrder(node.left, path)
        node.right && preOrder(node.right, path)
    }
    
    preOrder(root, '')
    return result
}


const t = {
    val: 1,
    left: { val: 2, left: null, right: { val: 5, left: null, right: null } },
    right: { val: 3, left: null, right: null },
}