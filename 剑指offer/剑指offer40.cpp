class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k <= 0 || arr.empty()) {
            return {};
        }

        if (arr.size() < k) {
            return arr;
        }

        priority_queue<int> h;

        for (auto cur : arr) {
            h.push(cur);

            if (h.size() > k) {
                h.pop();
            }
        }

        vector<int> res;

        while (!h.empty()) {
            res.push_back(h.top());
            h.pop();
        }

        return res;
    }
};

class Solution {
    vector<int> h;
    int n = 0;

    void sink(int i) {
        int j = 0;
        int t = h[i];

        // 依次找到i节点的左子节点
        // 左: i * 2 + 1
        // 右: i * 2 + 2
        while ((j = (i << 1) + 1) < n) {
            // j < n - 1判断是否有右结点
            // 有右结点的话，并且右结点更大，j指向右结点
            if (j < n - 1 && h[j] < h[j + 1]) {
                j++;
            }

            // 如果子结点比t大, 则交换位置
            if (h[j] > t) {
                h[i] = h[j]; // j上浮
                i = j;       // i = j继续往下对比
            } else {
                break;
            }
        }

        h[i] = t;
    }

    void swim(int i) {
        int par = 0;
        int t = h[i];

        while (i > 0) {
            // 父节点 = (i - 1) * 2
            par = (i - 1) >> 1;

            // 如果父节点小, 则交换位置
            if (h[par] < t) {
                h[i] = h[par];
                i = par;
            } else {
                break;
            }
        }

        h[i] = t;
    }

    void push(int v) {
        h[n++] = v;
        swim(n - 1);
    }

    int pop() {
        int ret = h[0];
        h[0] = h[--n];
        sink(0);
        return ret;
    }
    
    int empty() { return n == 0; }
    int size() { return n; }
    
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k <= 0 && arr.empty()) return {};
        if (k > arr.size()) return arr;
        vector<int> res; 

        h.resize(k + 1);

        for (auto cur : arr) {
            push(cur);

            if (size() > k) {
                pop();
            }
        }

        while (!empty()) {
            res.push_back(pop()); 
        }
        
        return res;
    }
};