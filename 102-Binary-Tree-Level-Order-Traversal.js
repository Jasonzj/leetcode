/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
const levelOrder = function(root) {
    const result = []
    const preOrder = function(node, depth) {
        if (!node) return
        if (result[depth]) result[depth].push(node.val)
        else result[depth] = [node.val]
        
        node.left && preOrder(node.left, depth + 1)
        node.right && preOrder(node.right, depth + 1)
    }
    
    preOrder(root, 0)
    return result
}