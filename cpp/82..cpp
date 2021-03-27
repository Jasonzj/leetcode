/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy('1');
        ListNode* tail = &dummy;

        while (head) {
            bool isRep = false;
            // 比较当前和下一个的值，如果相同一直走到最后一个重复项
            while (head->next && head->val == head->next->val) {
                head = head->next;
                isRep = true;
            }
            if (isRep) {
                // 指向最后一个重复项的下一个
                head = head->next;
            } else {
                // 不是重复，直接添加到新链表的结尾 
                tail->next = head;
                tail = tail->next;
                // 指向下一个，继续遍历
                head = head->next;
            }
        }

        // 如果链表最后一个是重复项，要把tail后清空
        tail->next = nullptr;

        return dummy.next;
    }
};
// @lc code=end

