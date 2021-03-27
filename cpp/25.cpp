/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
 // 利用新链表+桟，k个入栈, K个取出
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 1 || !head) return head;

        stack<ListNode*> s;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* tmp = &dummy;

        // 取出k个作为桟的初始值
        for (int i = 0; i < k; i++) {
            s.push(head);
            head = head->next;
        }

        while (!s.empty()) {
            // 取出k个, 添加到链尾
            while (!s.empty()) {
                tail->next = s.top();
                s.pop();
                tail = tail->next;
            }
    
            // 保留下每k个节点的后一个, 如果链表长度为K的倍数，tmp为null
            tmp = head;
            
            // 如果剩下长度满足k, 取出k个入栈, 否则清空桟
            for (int i = 0; i < k; i++) {
                if (head) {
                    s.push(head);
                    head = head->next;
                } else {
                    stack<ListNode*> tmp;
                    s = tmp;
                }
            }
        }
        
        // 如果tmp为空，清理尾指针, 否则把剩下不满足k长度的链到尾部
        tail->next = tmp;

        return dummy.next;
    }
};
// @lc code=end

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 1 || !head) return head;

        stack<ListNode*> s;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* tmp = &dummy;

        while (true) {
            int count = 0;
            // 取出k个入栈
            while (head && count < k) {
                s.push(head);
                head = head->next;
                count++;
            }

            // 剩余不足k个，或走完了链表 
            if (count != k) {
                // 如果tmp为空，清理尾指针, 否则把剩下不满足k长度的链到尾部
                tail->next = tmp;
                break;
            }
            
            // 出栈k个, 添加到链尾
            while (!s.empty()) {
                tail->next = s.top();
                s.pop();
                tail = tail->next;
            }
            
            // 保留下每k个节点的后一个, 如果链表长度为K的倍数，tmp为null
            tmp = head;
        }
        
        return dummy.next;
    }
};
