/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const reverseList = function (head) {
    let prev = null
    let node = head
    while (node) {
        let next = node.next
        node.next = prev
        prev = node
        node = next
    }
    return prev
};