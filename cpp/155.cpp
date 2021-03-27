class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> arr;
    int _min = INT_MAX;
    
    MinStack() {
    }
    
    void push(int x) {
        arr.push_back(x);
        if (x < _min) {
            _min = x;
        }
    }
    
    void pop() {
        int top = arr.back();
        arr.pop_back();
        if (arr.empty()) {
            _min = INT_MAX;
            return;
        }
        if (top == _min) {
            int m = arr.front();
            for (auto value:arr) {
                if (value < m) {
                    m = value;
                }
            }
            _min = m;
        }
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return _min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
private:
    stack<pair<int, int>> s;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s.emplace(x, s.empty() ? x : min(x, getMin()));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};