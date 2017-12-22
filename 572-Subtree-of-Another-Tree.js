/* ------------------------------------------------------------------- */

const tree1 = {
    val: 3,
    left: {
        val: 4,
        left: { val: 1, left: null, right: null },
        right: { val: 2, left: null, right: null }
    },
    right: { val: 5, left: null, right: null }
}

const tree2 = {
    val: 4,
    left: { val: 1, left: null, right: null },
    right: { val: 2, left: null, right: null }
}

/* ------------------------------------------------------------------- */

const isSubtree = function(s, t) {
    const tree1 = preorder(s, true)
    const tree2 = preorder(t, true)
    return tree1.includes(tree2)
}

const preorder = function (t, left) {
    if (t == null) {
        if (left)
        return "lnull"
        else
        return "rnull"
    }
    return "#" + t.val + " " + preorder(t.left, true) + " " + preorder(t.right, false)
}

/* ------------------------------------------------------------------- */

const isSubtree = function(s, t) {
    if (!s) return false
    if (isSame(s, t)) return true
    return isSubtree(s.left, t) || isSubtree(s.right, t)
}

const isSame = function(s, t) {
    if (!s && !t) return true
    if (!s || !t) return false
    if (s.val !== t.val) return false
    return isSame(s.left, t.left) && isSame(s.right, t.right)
}