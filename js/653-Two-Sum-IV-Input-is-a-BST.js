/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {boolean}
 */
const findTarget = function (root, k) {
    const map = {}
    const find = function (node, k, map) {
        if (!node) return false
        if (map[k - node.val]) return true
        map[node.val] = 1
        return find(node.left, k, map) || find(node.right, k, map)
    }
    return find(root, k, map)
}