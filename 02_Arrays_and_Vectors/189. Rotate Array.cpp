class Solution {
public:
  void reverseHelper(vector<int> &nums, int left, int right) {
    while (left <= right) {
      swap(nums[left], nums[right]);
      left++;
      right--;
    }
  }
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;
    reverseHelper(nums, 0, n - 1);
    reverseHelper(nums, 0, k - 1);
    reverseHelper(nums, k, n - 1);
  }
};