/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0); 
        ListNode* tail = &dummy;

        while (head != NULL) { 
            if (head->val != val) {
                tail->next = head;
                tail = tail->next;
            }
            head = head->next;
        }

        tail->next = nullptr;

        return dummy.next;
    }
};
// @lc code=end

