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
 * @return {number[][]}
 */
const pathSum = function(root, sum) {
    const result = []
    const searchSum = function (root, sum) {
        if (!root) return false
        if (!root.left && !root.right && sum - root.val === 0) {
            let node = root
            let path = []
            while (node) {
                path.unshift(node.val)
                node = node.parent
            }
            result.push(path)
        }
        
        sum -= root.val
        if (root.left) root.left.parent = root
        if (root.right) root.right.parent = root
        searchSum(root.left, sum)
        searchSum(root.right, sum)
    }
    
    searchSum(root, sum)
    
    return result
}

const pathSum = function(root, sum) {
    let q = []
    const result = []
    const searchSum = function (root, sum) {
        if (!root) return false
        
        q.push(root.val)
        
        if (!root.left && !root.right && sum - root.val === 0) {
            result.push(q.slice())
        }
        
        sum -= root.val
        searchSum(root.left, sum)
        searchSum(root.right, sum)
        q.pop()
    }
    
    searchSum(root, sum)
    
    return result
}
