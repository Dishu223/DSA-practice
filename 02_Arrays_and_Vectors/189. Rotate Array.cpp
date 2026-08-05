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

/*
 * Time Complexity: O(N) - Total traversal visits each element a constant number of times (3 reversals).
 * Space Complexity: O(1) - Performed in-place without using extra array memory.
 *
 * Summary:
 * Rotates array right by k steps using 3 reversals: first reverse the entire array,
 * then reverse the first k elements, and finally reverse the remaining n-k elements.
 */