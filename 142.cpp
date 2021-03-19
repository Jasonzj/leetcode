/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 空链表和只有一个结点无环
        if (!head || !head->next) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                break;
            }
        }

        //  链表不存在环，直接返回null 
        if (slow != fast) {
            return nullptr;
        }
        
        // slow指针重新指向head
        slow = head;
        
        // slow指针从head出发, fast指针从相遇位置出发
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // 返回环形的入口结点
        return slow;
    }
};
// @lc code=end

