/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} t
 * @return {string}
 */
const tree2str = function (t) {
    if (!t) return ''
    if (!t.left && !t.right) return t.val + ''
    if (!t.right) return t.val + `(${tree2str(t.left)})`
    return `${t.val}(${tree2str(t.left)})(${tree2str(t.right)})`
}


const tree2str = function (t) {
    if (!t) return ""
    const output = "" + t.val
    const left = tree2str(t.left)
    const right = tree2str(t.right)
    if (left && right) {
        output += "(" + left + ")(" + right + ")"
    }
    else if (right) {
        output += "()(" + right + ")"
    }
    else if (left) {
        output += "(" + left + ")"
    }
    return output
}