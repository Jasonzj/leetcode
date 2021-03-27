/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

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
 // 双指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

// 新链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        // 遍历旧链表，采用头部插入到新链表
        while (head != NULL) { 
            ListNode* next = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = next;
        }

        return dummy.next;
    }
};