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
const deleteDuplicates = function (head) {
    let cur = head
    while (cur && cur.next) {
        let next = cur.next
        if (cur.val == next.val) {
            cur.next = next.next
        } else {
            cur = next
        }
    }
    return head
}