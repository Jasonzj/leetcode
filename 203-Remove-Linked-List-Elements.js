/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
const removeElements = function (head, val) {
    if (!head) return null
    
    let node = head
    while (node && node.next) {
        const next = node.next
        if (next.val === val) node.next = next.next
        else node = node.next
    }

    return head.val == val ? head.next : head
}