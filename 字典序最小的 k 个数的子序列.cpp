// 【题目】给定一个正整数数组和 k，要求依次取出 k 个数，输出其中数组的一个子序列，需要满足：1. 长度为 k；2.字典序最小。

// 输入：nums = [3,5,2,6], k = 2
// 输出：[2,6]

vector<int> findSmallSeq(vector<int> &nums, int k) {
  if (nums.empty()) return {};

  vector<int> ans(nums.size());
  stack<int> s; // 递增桟

  for (int i = 0; i < nums.size(); i++) {
    int v = nums[i];
    int right = nums.size() - i;

    while (!s.empty() && s.top() > v && ((int)s.size() + right > k)) {
      s.pop();
    }
    
    s.push(v);
  }

  // 取k个
  while ((int)s.size() > k) {
    s.pop();
  }

  for (int i = k - 1; i >= 0; i--) {
    ans[i] = s.top();
    s.pop();
  }

  return ans;
}
