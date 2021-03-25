/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        
        while (cur && cur->next) {

            if (cur->next->val == val) {
                cur->next = cur->next->next;
                break;
            }
            
            cur = cur->next;
        }
        
        return dummy.next;
    }
};