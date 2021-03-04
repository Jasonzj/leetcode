/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
const hasPathSum = function(root, sum) {
    if(!root) return false
    
    if(!root.left && !root.right && sum - root.val == 0) return true
    
    return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val)
}