/**
 * Definition for binary tree
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @constructor
 * @param {TreeNode} root - root of the binary search tree
 */
const BSTIterator = function(root) {
    this.stack = []
    pushAll(root, this.stack)
}


/**
 * @this BSTIterator
 * @returns {boolean} - whether we have a next smallest number
 */
BSTIterator.prototype.hasNext = function() {
    return this.stack.length > 0
}

/**
 * @this BSTIterator
 * @returns {number} - the next smallest number
 */
BSTIterator.prototype.next = function() {
    const tmpNode = this.stack.pop()
    pushAll(tmpNode.right, this.stack)
    return tmpNode.val
}

const pushAll = function(node, stack) {
    while (node != null) {
        stack.push(node)
        node = node.left
    }   
}

/**
 * Your BSTIterator will be called like this:
 * var i = new BSTIterator(root), a = []
 * while (i.hasNext()) a.push(i.next())
*/

const t = {
    val: 3,
    left: {
        val: 4,
        left: { val: 1, left: null, right: null },
        right: { val: 2, left: null, right: null }
    },
    right: {
        val: 5, left: null, right: null
    }
}

const i = new BSTIterator(t)
const a = []
while (i.hasNext()) {
    a.push(i.next())
}