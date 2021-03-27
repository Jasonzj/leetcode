/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* back = &dummy;
        ListNode* front = &dummy;
        int count = 0;

        // front指针先走n步
        while (count < n && front && front->next) {
            front = front->next;
            count++;
        }

        // back, front 一起走, front走到最后一个节点停止
        while (front && front->next) {
            back = back->next;
            front = front->next;
        }

        // 链表长度 >= n
        if (count == n){ 
            // 此时back指向目前的前一个
            // 删除
            back->next = back->next->next;
        }

        return dummy.next;
    }
};
// @lc code=end

