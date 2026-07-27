class KthLargest {
public:
  int k;
  priority_queue<int, vector<int>, greater<int>> dibyaheap;
  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    for (int i : nums) {
      add(i);
    }
  }

  int add(int val) {
    dibyaheap.push(val);
    if (dibyaheap.size() > k) {
      dibyaheap.pop();
    }

    return dibyaheap.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */