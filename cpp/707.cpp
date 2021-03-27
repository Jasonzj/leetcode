/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
    struct ListNode {
        int val = 0;
        ListNode* next = nullptr;
        ListNode() {};
        ListNode(int x) { val = x; };
    };

    ListNode dummy;
    ListNode* tail = nullptr;
    int length = 0;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        tail = &dummy;
    }

    ListNode* getPreNode(int index) {
        auto back = &dummy;
        auto front = dummy.next; 
        for (int i = 0; i < index; i++) {
           back = front; 
           front = front->next;
        }
        return back;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= length) {
            return -1;
        }
        return getPreNode(index)->next->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = dummy.next;
        dummy.next = p;
        if (tail == &dummy) {
            tail = p;
        }
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
        length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length) {
            return;
        } else if (index == length) {
            addAtTail(val);
            return;
        } else if (index <= 0) {
            addAtHead(val);
            return;
        }
        ListNode* prev = getPreNode(index);
        ListNode* p = new ListNode(val);
        p->next = prev->next;
        prev->next = p;
        length++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= length || index < 0) {
            return;
        }

        ListNode* prev = getPreNode(index);

        if (tail == prev->next) {
            tail = prev;
        }

        prev->next = prev->next->next;
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

