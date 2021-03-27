/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        bool c = false;
        
        while (l1 || l2) {
            int a, b, res;
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            res = c ? a + b + 1 : a + b;
            c = res / 10 ? true : false;
            res %= 10;
            
            tail->next = new ListNode(res);
            tail = tail->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;    
        }
        
        tail->next = c ? new ListNode(1) : nullptr;
        
        return dummy.next;
    }
};
// @lc code=end

