/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
// 快慢指针
// k < len, 利用快慢指针找到倒数第k个节点的前驱节点
// k = len, 直接返回
// k > len, 利用快慢指针计算长度，算出从链尾走到倒数第(k % len)节点的前驱节点所需的步数
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* res = nullptr;
        int count = k;
        
        // 快指针先走k步, 最多走到链尾，如果k > len, count > 1
        while (fast->next && count--) {
           fast = fast->next;
        }
        
        if (count == 1) {
            return head;
        }
        
        // k > len
        if (count > 1) {
            int len = (k - count + 1);
            // 算出从链尾走到倒数第(k % len)节点的前驱节点所需的步数
            k = len - k % len;
            // k > len, 此时 fast 位于链尾，链接头成环 
            fast->next = head;
            // 走到最终结果最后一个节点
            while (k--) {
                fast = fast->next;
            }
            slow = fast;
        } else {
            // k < len 正常用快慢指针找到倒数第k个节点的前驱节点
            while (fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
            // 到了链尾，链接成环
            fast->next = head;
        }
        
        // slow 指向最终结果的最后一个节点
        // 拿到slow->next, 最终结果的头节点
        res = slow->next;
        // 断链
        slow->next = nullptr;
        
        return res;
    }
};
// @lc code=end

