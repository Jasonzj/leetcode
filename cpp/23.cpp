/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [&](ListNode* a, ListNode* b) {
            return b->val < a->val;
        };
        
        ListNode res(0), *tail = &res;
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> h(cmp);   // 小堆
        
        for (auto& l : lists) {
            if (l) h.push(l);
        }
        
        while (!h.empty()) {
            auto t = h.top();
            h.pop();
            tail->next = t;
            tail = t;
            if (t->next) {
                h.push(t->next);
            }
        }
        
        return res.next;
    }
};
// @lc code=end

