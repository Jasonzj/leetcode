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
const isSymmetric = function(root) {
    return isMirror(root, root)
}

const isMirror = function(t1, t2) {
    if (!t1 && !t2) return true
    if (!t1 || !t2) return false
    return (t1.val === t2.val)
        && isMirror(t1.left, t2.right)
        && isMirror(t1.right, t2.left)
}