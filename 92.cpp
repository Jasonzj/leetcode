/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
 // 新链表+桟，判断范围
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> s;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int count = 0;

        while (head) {
            count++;
            // 在范围内，利用桟反转
            if (count >= left && count <= right) {
                while (count <= right) {
                    s.push(head);
                    head = head->next;
                    count++;
                }

                while (!s.empty()) {
                    tail->next = s.top();
                    s.pop();
                    tail = tail->next;
                }
            } else {   // 不在范围内正常添加到新链表尾部
                tail->next = head;
                tail = tail->next;
                head = head->next;
            }
        }

        // 清空尾指针 
        tail->next = nullptr;

        return dummy.next;
    }
};
// @lc code=end

