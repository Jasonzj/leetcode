/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
 // 拆分链表，然后反转后链表，合并
class Solution {
private:
    // 反转链表
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

    // 找到中值 
    ListNode* findMiddleNode(ListNode* head) {
        ListNode* s1 = head;
        ListNode* s2 = head;
        ListNode* pre = s1;
        
        while (s2 && s2->next) {
            pre = s1;
            s1 = s1->next;
            s2 = s2->next->next;
        } 
        
        return s2 ? s1 : pre;
    }
    
public:
    void reorderList(ListNode* head) {
        ListNode* mid = findMiddleNode(head);
        ListNode* back = mid->next;
        mid->next = nullptr;
        back = reverseList(back);
        
        // 合并链表
        ListNode* tmp1;
        ListNode* tmp2;
        while (head && back) {
            tmp1 = head->next;
            tmp2 = back->next;
            
            head->next = back;
            head = tmp1;
            
            back->next = head;
            back = tmp2;
        }
    }
};
// @lc code=end

