/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
private:
    ListNode* findMiddleNode(ListNode* head) {
        ListNode* s1 = head;
        ListNode* s2 = head;
        ListNode* prev = s1;

        // 如果链表长度是奇数, s2最后不为NULL, 偶数为NULL
        while (s2 && s2->next) {
            // 保留慢指针前驱结点
            prev = s1;
            s1 = s1->next;
            s2 = s2->next->next;
        }

        return s2 ? s1 : pre; 
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next;

        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head) return head;

        ListNode* mid = findMiddleNode(head);
        ListNode* back = reverseList(mid->next);
        mid->next = nullptr;

        while (back) {
            if (head->val != back->val) {
                return false;
            }
            head = head->next;
            back = back->next;
        }

        return true;
    }
};
// @lc code=end

