/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
 // 新链表，每次判断是否与尾部相等
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy('1');
        ListNode* tail = &dummy;

        while (head != NULL) { 
            if (head->val != tail->val) {
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

// 直接修改原链表
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        
        return head;
    }
};
