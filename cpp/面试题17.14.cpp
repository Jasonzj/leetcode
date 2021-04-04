class Solution {
    void kth (vector<int> &arr, int start, int end, int k) {
        if (start >= end || start + 1 >= end) return;
        
        int mid = start + ((end - start) >> 1);
        int x = arr[mid];
        int l = start, i = start, r = end - 1;
        
        while (i <= r) {
            if (arr[i] < x) {
                swap(arr[l++], arr[i++]);
            } else if (arr[i] == x) {
                i++;
            } else {
                swap(arr[r--], arr[i]);
            }
        }
        
        int lcnt = l - start;
        int mcnt = i - l;
        
        if (k <= lcnt) {
            kth(arr, start, l, k);
        }
        
        if (k >= (lcnt + mcnt)) {
            kth(arr, i, end, k - lcnt - mcnt);
        }
        
        return;
    }
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k < 1) return {};
        
        kth(arr, 0, arr.size(), k - 1);
        vector<int> res(arr.begin(), arr.begin() + k);
        
        return res;
    }
};