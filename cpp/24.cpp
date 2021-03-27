/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
 // 利用新链表+桟，两两入栈, 两两取出
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        stack<ListNode*> s;
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (head && head->next) {
            s.push(head);
            s.push(head->next);

            head = head->next->next;

            tail->next = s.top();
            s.pop();
            tail = tail->next;

            tail->next = s.top();
            s.pop();
            tail = tail->next;
        }

        if (head == NULL) {
            // 链表为偶数
            tail->next = nullptr;
        } else {
            // 链表为奇数
            tail->next = head;
        }

        return dummy.next;
    }
};
// @lc code=end

