/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
 // 迭代归并
class Solution {
    ListNode* split(ListNode* head, int index) {
        if (!head) return nullptr;

        ListNode* cur = head;

        while (index-- > 1 && cur->next) {
            cur = cur->next;
        }

        ListNode* back = cur->next;
        cur->next = nullptr;
        
        return back;
    }

    ListNode* merge(ListNode* i, ListNode* j) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (i && j) {
           if (i->val < j->val) {
               tail->next = i;
               i = i->next;
           } else {
               tail->next = j;
               j = j->next;
           }
           tail = tail->next;
        }
        
        if (i == NULL) { tail->next = j; }
        if (j == NULL) { tail->next = i; }

        return dummy.next;
    }

    int getListLength(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }
public:
    ListNode* sortList(ListNode* head) {
        // 无节点, 或者只有一个节点直接返回 
        if (!head || !head->next) {
            return head;
        }
        
        int length = getListLength(head);
        ListNode dummy;
        dummy.next = head;

        // 根据step每次切分，1，2，4，8...
        // 每次循环从按step切分合并排序
        for (int step = 1; step < length; step <<= 1) { 
            ListNode* prev = &dummy;
            ListNode* cur = dummy.next;

            while (cur) {
                ListNode* h1 = cur;              // 第一部分头
                ListNode* h2 = split(h1, step);  // 第二部分头
                cur = split(h2, step);           // cur = 剩余部分头
                ListNode* temp = merge(h1, h2);  // 排序合并第一第二部分
                prev->next = temp;               // 将前面排序好部分和后面排序好部分链接
                while (prev->next) {               
                    prev = prev->next;           // 将prev指针移到排序好部分的尾部
                }
            }
        }

        return dummy.next;
    }
};
// @lc code=end

// 递归 + 归并
class Solution {
    ListNode *findMiddleNode(ListNode * head) {
        ListNode* s1 = head;
        ListNode* s2 = head->next;
        ListNode* prev = s1;

        while (s2 && s2->next) {
            prev = s1;
            s1 = s1->next;
            s2 = s2->next->next;
        }

        return s2 ? s1 : prev;
    }
    
    ListNode* merge(ListNode* i, ListNode* j) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (i && j) {
           if (i->val < j->val) {
               tail->next = i;
               i = i->next;
           } else {
               tail->next = j;
               j = j->next;
           }
           tail = tail->next;
        }
        
        if (i == NULL) { tail->next = j; }
        if (j == NULL) { tail->next = i; }

        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* mid = findMiddleNode(head);
        ListNode* back = mid->next;
        mid->next = nullptr;    // 断链

        return merge(sortList(head), sortList(back));
    }
};
