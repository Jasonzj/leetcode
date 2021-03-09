/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
public:
    // [front, tail]
    int front = 0;      // 第一个元素下标
    int tail = -1;      // 最后一个元素下标
    int used = 0;       // 已使用元素个数
    int capacity = 0;   // 循环队列最多能存放元素个数
    vector<int> q;

    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
 
        tail = (tail + 1) % capacity;
        q[tail] = value;
        used++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % capacity;
        used--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[tail % capacity]; 
    }
    
    bool isEmpty() {
        return used == 0;
    }
    
    bool isFull() {
        return used == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

