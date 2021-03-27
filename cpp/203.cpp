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
 // 新链表，按条件添加到尾部
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0); 
        ListNode* tail = &dummy;

        while (head) { 
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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy;
        dummy.next = head;
        ListNode* cur = &dummy;
        
        while (cur && cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};
// @lc code=end

